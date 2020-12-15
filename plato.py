import os
import sys
import re

# -- Unpack all arguments for parsing.  Arguments come in pairs, with the argument name prefixed by '--'.
args = {x:y for x, y in re.findall(r'--(\S+)\s+(\S+)', ''.join([x + ' ' for x in sys.argv[1:]]))}

# -- These are the only arguments we use currently.  Arguments can be specified in any order.
target_template_name = args.get('template', None)
project_root = args.get('root', None)
class_name = args.get('name', None).lower()
plato_dir = os.path.dirname(sys.argv[0])

# -- If no class name is given, exit.
print 'class name %s' % class_name
if class_name is None:
  print('\033[91mERROR: No class name provided.\033[0m')
  sys.exit()

# -- Warn if no template is specified.
if target_template_name is None:
  print('\033[93mWARNING: No template specified, defaulting to "template" if exists...\033[0m')
  target_template_name = 'template'

# -- Check the template files exist.
template_dir = os.path.join(plato_dir, 'templates')
template_source = target_template_name + '.cpp'
template_header = target_template_name + '.h'

if (not os.path.exists(os.path.join(template_dir, template_source))) or (not os.path.exists(os.path.join(template_dir, template_header))):
  print('\033[91mERROR: Missing template files for "%s".\033[0m' % tar)
  sys.exit()

# -- Plato is run under project root, assume there's an include & src folder.
HEADER_DESTINATION = os.path.normpath(os.path.join(project_root, 'include')).replace('\\', '/')
SOURCE_DESTINATION = os.path.normpath(os.path.join(project_root, 'src')).replace('\\', '/')

if HEADER_DESTINATION[-1] != '/':
  HEADER_DESTINATION += '/'

if SOURCE_DESTINATION[-1] != '/':
  SOURCE_DESTINATION += '/'

project_header_root = HEADER_DESTINATION

# -- Raw input to grab any more detailed paths the user wants.
header_subdir = raw_input('Header Path:\t%s' % HEADER_DESTINATION)
source_subdir = raw_input('Source Path:\t%s' % SOURCE_DESTINATION)

HEADER_DESTINATION = os.path.normpath(
  os.path.join(
    HEADER_DESTINATION,
    header_subdir
    ) or HEADER_DESTINATION
  )

SOURCE_DESTINATION = os.path.normpath(
  os.path.join(
    SOURCE_DESTINATION,
    source_subdir
    ) or SOURCE_DESTINATION
  )

if HEADER_DESTINATION[-1] != '/':
  HEADER_DESTINATION += '/'

if SOURCE_DESTINATION[-1] != '/':
  SOURCE_DESTINATION += '/'

target_header_file = os.path.join(HEADER_DESTINATION, '%s.h' % class_name)
target_source_file = os.path.join(SOURCE_DESTINATION, '%s.cpp' % class_name)

check_proceed = None

print 'Will create the following files:\n\t%s\n\t%s' % (target_header_file, target_source_file)
while check_proceed not in ['y', 'n', 'yes', 'no']:
  check_proceed = raw_input('Continue?: ').lower().strip(' ')

if check_proceed in ['no', 'n']:
  sys.exit()

missing_dirs = [x for x in [HEADER_DESTINATION, SOURCE_DESTINATION] if not os.path.isdir(x)]

if len(missing_dirs):
  check_proceed = None
  print 'Will create the following directories:'
  for missing_dir in missing_dirs:
    print '\t%s' % missing_dir

  while check_proceed not in ['y', 'n', 'yes', 'no']:
    check_proceed = raw_input('Continue?: ').lower().strip(' ')

  if check_proceed in ['no', 'n']:
    sys.exit()

  for missing_dir in missing_dirs:
    os.makedirs(missing_dir)

with open(os.path.join(template_dir, template_header), 'r') as fp:
  header_str = fp.read()

with open(os.path.join(template_dir, template_source), 'r') as fp:
  source_str = fp.read()

header_str = header_str\
  .replace('__PLATO_VAR_CLASSNAME__', class_name.upper())\
    .replace('__PLATO_VAR_Classname__', class_name.capitalize())\
      .replace('__PLATO_VAR_classname__', class_name.lower())

source_str = source_str\
  .replace('__PLATO_VAR_CLASSNAME__', class_name.upper())\
    .replace('__PLATO_VAR_Classname__', class_name.capitalize())\
      .replace('__PLATO_VAR_classname__', class_name.lower())\
        .replace('__PLATO_VAR_header_path__', target_header_file.replace(project_header_root, ''))

with open(target_header_file, 'w+') as fp:
  fp.write(header_str)

with open(target_source_file, 'w+') as fp:
  fp.write(source_str)

print('\033[92mSuccessfully created source/header files for %s\033[0m' % class_name)