#include <iostream>
#include <functional>

/**
 * Macros to make writing lots of embedded lambdas less tedious
 *
 * eg. this:
 *
 *     λf.λx.f x
 *
 * becomes this:
 * 
 *     $(f)_($(x)_(f (x)));
 */
#define $(x) [&](auto x)
#define _(x) {return x;}

// Yet another tedious-less macro
#define $$ const auto

using namespace std;

// Helper functions to convert from Church types to C++ types.
$$ to_int = $(f)_(f ($(x)_(x+1ull)) (0ull));

$$ to_bool = $(f)_(f (true) (false));

int main()
{
  $$ ZERO  = $(f)_($(x)_(               x));      // λf.λx.x
  $$ ONE   = $(f)_($(x)_(            f (x)));     // λf.λx.f x
  $$ TWO   = $(f)_($(x)_(         f (f (x))));    // λf.λx.f (f x)
  $$ THREE = $(f)_($(x)_(      f (f (f (x)))));   // λf.λx.f (f (f x))
  $$ FIVE  = $(f)_($(x)_(f (f (f (f (f (x))))))); // etc...

  $$ FIFTEEN  =
    $(f)_($(x)_(f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (x)))))))))))))))));
  $$ HUNDRED  =
    $(f)_($(x)_(f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (f (
    f (f (f (f (x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
    ))))))))))))))))))))))))))))))))))))))));

  $$ TRUE = $(x)_($(y)_(x));  // λx.λy.x
  $$ FALSE = $(x)_($(y)_(y)); // λx.λy.y

  // syntactic sugar.
  $$ IF = $(b)_(b);

  // λn.n (λx.FALSE) TRUE
  $$ ISZERO = $(n)_(n ($(x)_(FALSE)) (TRUE));

  // λn.λf.λx.f (n f x)
  $$ SUCC = $(n)_($(f)_($(x)_(f (n (f) (x)))));

  // λm.λn.m SUCC n
  $$ PLUS = $(m)_($(n)_(m (SUCC) (n)));

  // λm.λn.m (PLUS n) ZERO
  $$ MULT = $(m)_($(n)_(m (PLUS (n)) (ZERO)));

  // WARNING: doesn't seem to work with (tested with clang++)
  // λn.λf.λx.n (λg.λh.h (g f)) (λu.x) (λu.u)
  $$ PRED = $(n)_($(f)_($(x)_(
    n ($(g)_($(h)_(h (g (f))))) ($(u)_(x)) ($(u)_(u)) )));

  return 0;
}