#ifndef NU_RAFT_HXX
#define NU_RAFT_HXX

template <typename> struct void_type { typedef void type; };

template <typename T, typename = void>
struct default_completion_token_impl
{
  typedef void type;
};

template <typename T>
struct default_completion_token_impl<T,
  typename void_type<typename T::default_completion_token_type>::type>
{
  typedef typename T::default_completion_token_type type;
};

template <typename T>
struct default_completion_token
  : default_completion_token_impl<T>
{
};

template <typename Executor>
class basic_waitable_timer
{
public:
    typedef Executor execute_type;
    basic_waitable_timer() = default;
    template <
        typename WaitToken = typename default_completion_token<execute_type>::type> 
    auto async_wait(WaitToken && token = default_completion_token<execute_type>::type())
    {

    }
};

#endif
