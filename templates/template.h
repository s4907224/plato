#ifndef GBOX___PLATO_VAR_CLASSNAME___H
#define GBOX___PLATO_VAR_CLASSNAME___H

#include <iostream>

namespace gbox
{
  class __PLATO_VAR_Classname__
  {
    public:
      // dtor
      ~__PLATO_VAR_Classname__();
      // ctor
      __PLATO_VAR_Classname__();
      // copy ctor
      __PLATO_VAR_Classname__(const __PLATO_VAR_Classname__& ___PLATO_VAR_classname___other);
      // copy assignment operator
      __PLATO_VAR_Classname__& operator=(const __PLATO_VAR_Classname__& ___PLATO_VAR_classname___other);
      // move ctor
      __PLATO_VAR_Classname__(__PLATO_VAR_Classname__&& ___PLATO_VAR_classname___other);
      // move assignment operator
      __PLATO_VAR_Classname__& operator=(__PLATO_VAR_Classname__&& ___PLATO_VAR_classname___other);
      // property for ID
      const int& ID() {return m_ID;}

    private:
      static int m_instance_counter;
      int m_ID;
  };// class __PLATO_VAR_Classname__
}// namespace gbox

#endif // GBOX__PLATO_VAR_CLASSNAME__H