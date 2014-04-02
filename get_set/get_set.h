#ifndef RG_GET_SET

# if __cplusplus <= 199711L
#  define rgSet(var, name, scope)		\
  scope:					\
  inline void name(typeof(var) value) throw()	\
  {						\
    var = value;				\
  }

#  define rgGet(var, name, scope)			\
  scope:						\
  inline const typeof(var) &name(void) const throw()	\
  {							\
    return (var);					\
  }

# else

#  define rgSet(var, name, scope)		\
  scope:					\
  inline void name(decltype(var) value) throw()	\
  {						\
    var = value;				\
  }

#  define rgGet(var, name, scope)			\
  scope:						\
  inline const decltype(var) &name(void) const throw()	\
  {							\
    return (var);					\
  }

# endif

# ifdef RG_NO_PREFIX

#  define get(...) rgGet( __VA_ARGS__ )

#  define set(...) rgSet( __VA_ARGS__ )

# endif  

#endif
