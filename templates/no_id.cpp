#include "__PLATO_VAR_header_path__"

gbox::__PLATO_VAR_Classname__::__PLATO_VAR_Classname__()
{
  m_ID = m_instance_counter++;

  #ifdef DEBUG_PRINTS
  std::cout<<"Ctor called for __PLATO_VAR_Classname__ @"<<std::hex<<this<<std::dec<<'\n';
  #endif
}

gbox::__PLATO_VAR_Classname__::~__PLATO_VAR_Classname__()
{
  #ifdef DEBUG_PRINTS  
  std::cout<<"Dtor called for __PLATO_VAR_Classname__ @"<<std::hex<<this<<std::dec<<'\n';
  #endif
}

gbox::__PLATO_VAR_Classname__::__PLATO_VAR_Classname__(const __PLATO_VAR_Classname__& ___PLATO_VAR_classname___other)
{
  m_ID = m_instance_counter++;

  #ifdef DEBUG_PRINTS
  std::cout<<"Copy ctor called for __PLATO_VAR_Classname__ and __PLATO_VAR_Classname__\n";
  #endif
}

gbox::__PLATO_VAR_Classname__& gbox::__PLATO_VAR_Classname__::operator=(const __PLATO_VAR_Classname__& ___PLATO_VAR_classname___other)
{
  #ifdef DEBUG_PRINTS
  std::cout<<"Copy assignment called for __PLATO_VAR_Classname__\n";
  #endif
  
  return *this;
}

gbox::__PLATO_VAR_Classname__::__PLATO_VAR_Classname__(__PLATO_VAR_Classname__&& ___PLATO_VAR_classname___other)
{
  #ifdef DEBUG_PRINTS
  std::cout<<"Move ctor called for __PLATO_VAR_Classname__ and __PLATO_VAR_Classname__\n";
  #endif
}

gbox::__PLATO_VAR_Classname__& gbox::__PLATO_VAR_Classname__::operator=(__PLATO_VAR_Classname__&& ___PLATO_VAR_classname___other)
{
  #ifdef DEBUG_PRINTS
  std::cout<<"Move assignment called for __PLATO_VAR_Classname__ and __PLATO_VAR_Classname__\n";
  #endif

  return *this;
}