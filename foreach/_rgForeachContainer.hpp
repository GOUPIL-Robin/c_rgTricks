#ifndef _RGFOREACHCONTAINER_HH_

template<class T>
class rgForeachContainer
{
public:
  typedef typename T::value_type value_type;

public:
  rgForeachContainer(T &cont) : _cont(cont)
  {
    _it = _cont.begin();
  }

  // cast the instance to bool so we can declare the variable in an if
  // ex: "if (rgForeachContainer< typeof(cont) > _container_ = cont)"
  operator bool() throw()
  {
    return (true);
  }

  // return the current iterator value
  value_type current(void)
  {
    return (*_it);
  }

  // increment the iterator
  bool next(void)
  {
    _it++;
    return (true);
  }

  // return true if the iterator has reached the end of the container
  bool end(void) const
  {
    return (_it == _cont.end());
  }

private:
  T &_cont;
  typename T::iterator _it;
};

#endif
