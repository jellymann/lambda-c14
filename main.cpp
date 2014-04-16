#include <iostream>
#include <functional>

#define $(x) [&](auto x)
#define _(x) {return x;}
#define $$ const auto

using namespace std;


$$ to_int = $(f)_(f ($(x)_(x+1ull)) (0ull));

$$ to_bool = $(f)_(f (true) (false));

int main()
{
  $$ ZERO  = $(f)_($(x)_(x));
  $$ ONE   = $(f)_($(x)_(f (x)));
  $$ TWO   = $(f)_($(x)_(f (f (x))));
  $$ THREE = $(f)_($(x)_(f (f (f (x)))));
  $$ FIVE  = $(f)_($(x)_(f (f (f (f (f (x)))))));

  $$ FIFTEEN  =
    $(f)_($(x)_(f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (x)))))))))))))))));
  $$ HUNDRED  =
    $(f)_($(x)_(f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
    ))))))))))))))))))))))))))))))))))))))));

  $$ TRUE = $(x)_($(y)_(x));
  $$ FALSE = $(x)_($(y)_(y));

  $$ IF = $(b)_(b);

  $$ ISZERO = $(n)_(n ($(x)_(FALSE)) (TRUE));

  $$ SUCC = $(n)_($(f)_($(x)_(f (n (f) (x)))));

  $$ PLUS = $(m)_($(n)_(m (SUCC) (n)));

  $$ MULT = $(m)_($(n)_(m (PLUS (n)) (ZERO)));

  $$ PRED = $(n)_($(f)_($(x)_(
    n ($(g)_($(h)_(h (g (f))))) ($(u)_(x)) ($(u)_(u)) )));

  cout << to_int(PRED (ONE)) << endl;

  return 0;
}