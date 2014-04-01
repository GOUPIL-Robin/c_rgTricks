#ifndef rgForeach

#include "_rgForeachContainer.hpp"


#define rgForeach(name, cont)						\
  if (rgForeachContainer< typeof(cont) > _container_ = cont)		\
    for (bool _still_ = true; !_container_.end(); _still_ = _container_.next())		\
	for (rgForeachContainer< typeof(cont) >::value_type name = _container_.current(); _still_; _still_ = false)

# ifndef rgForeach2

# define rgIn ,
# define rgForeach2(...)			\
  rgForeach( __VA_ARGS__ )

# endif

# ifdef RG_NO_PREFIX

# define in rgIn
# define foreach(...)				\
  rgForeach2(__VA_ARGS__ )

# endif

#endif
