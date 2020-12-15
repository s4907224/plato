#include "__PLATO_VAR_header_path__"

int gbox::__PLATO_VAR_Classname__::m_instance_counter = 0;

gbox::__PLATO_VAR_Classname__::__PLATO_VAR_Classname__()
{
  m_ID = m_instance_counter++;
  std::cout<<"Ctor called for __PLATO_VAR_Classname__ with ID "<<m_ID<<" @"<<std::hex<<this<<'\n';
}

gbox::__PLATO_VAR_Classname__::~__PLATO_VAR_Classname__()
{
  std::cout<<"Dtor called for __PLATO_VAR_Classname__ with ID "<<m_ID<<" @"<<std::hex<<this<<'\n';
}

gbox::__PLATO_VAR_Classname__::__PLATO_VAR_Classname__(const __PLATO_VAR_Classname__& ___PLATO_VAR_classname___other)
{
  m_ID = m_instance_counter++;
  std::cout<<"Copy ctor called for __PLATO_VAR_Classname__ with ID "<<m_ID<<" and __PLATO_VAR_Classname__ with ID "<<___PLATO_VAR_classname___other.m_ID<<'\n';
}

gbox::__PLATO_VAR_Classname__& gbox::__PLATO_VAR_Classname__::operator=(const __PLATO_VAR_Classname__& ___PLATO_VAR_classname___other)
{
  m_ID = ___PLATO_VAR_classname___other.m_ID;
  std::cout<<"Copy assignment called for __PLATO_VAR_Classname__ with ID "<<m_ID<<" and __PLATO_VAR_Classname__ with ID "<<___PLATO_VAR_classname___other.m_ID<<'\n';
  return *this;
}

gbox::__PLATO_VAR_Classname__::__PLATO_VAR_Classname__(__PLATO_VAR_Classname__&& ___PLATO_VAR_classname___other)
{
  m_ID = ___PLATO_VAR_classname___other.m_ID;
  std::cout<<"Move ctor called for __PLATO_VAR_Classname__ with ID "<<m_ID<<" and __PLATO_VAR_Classname__ with ID "<<___PLATO_VAR_classname___other.m_ID<<'\n';
  ___PLATO_VAR_classname___other.m_ID = -1;
}

gbox::__PLATO_VAR_Classname__& gbox::__PLATO_VAR_Classname__::operator=(__PLATO_VAR_Classname__&& ___PLATO_VAR_classname___other)
{
  m_ID = ___PLATO_VAR_classname___other.m_ID;
  std::cout<<"Move assignment called for __PLATO_VAR_Classname__ with ID "<<m_ID<<" and __PLATO_VAR_Classname__ with ID "<<___PLATO_VAR_classname___other.m_ID<<'\n';
  ___PLATO_VAR_classname___other.m_ID = -1;
  return *this;
}