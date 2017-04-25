<h1>The Push_swap project<h1>

<h2>This is algorithmic project which realize sorting the stack of integers.</h2><br>
<p>Here we have a spacial rules. First stack (stack A) contain the integers and second stack (stack B) is empty</p>
<p>We can use only next instruction:</p>

<b>sa</b> : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).<br>

<b>sb</b> : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).<br>

<b>ss</b> : sa and sb at the same time.<br>

<b>pa</b> : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.<br>

<b>pb</b> : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.<br>

<b>ra</b> : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.<br>

<b>rb</b> : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.<br>

<b>rr</b> : ra and rb at the same time.<br>

<b>rra</b> : reverse rotate a - shift down all elements of stack a by 1. The flast element
becomes the first one.<br>

<b>rrb</b> : reverse rotate b - shift down all elements of stack b by 1. The flast element
becomes the first one.<br>

<b>rrr</b> : rra and rrb at the same time.<br>

To compile executable use command `make`

The `push_swap` executable will generate the right list of instruction for sorting input integers.<br>
The `checker` executable will check instruction sorting list is right or wrong.<br>
The `random` executable will generate a random list of integers. (e.g. `./random 10 30` will generate `10` random numbers from `-30` to `30` without repeats)<br>

<h>Usage:</h>
```clj
 ./push_swap 50 33 23 -56 12 38 123 93 -12 | ./checker 50 33 23 -56 12 38 123 93 -12
```
or 
```clj
  ARG="`./random 20 50`"
 ./push_swap $ARG | ./checker $ARG
```
To enable visual mode use the `-v` flag whith `checker` (e.g. `./push_swap $ARG | ./checker $ARG -v`)<br><br>
![screenshot](https://github.com/Tempret/push_swap/blob/master/img/push_swap.png)
