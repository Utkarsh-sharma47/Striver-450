/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing 
at least one occurrence of all these characters a, b and c.
*/

/*
APPROACH:-
maintain a last seen index for a,b,c = ia,ib,ic
 for every index i,
- we need a smallest subtring which contans all the 3 chars and 
    ending at i index
that will start from min of {ia,ib,ic} =minindex to index i
- so for that index i , number of substrings possible are = minindex+1
(plus one so that we include that smallest string itselft )

eg: b b a c b
    0 1 2 3 4

    for index i = 4
    last occcurance of a,b,c are ia=2(min), ib=4, ic=3

    so possible substr are = ia+1;
    how: [acb], [b-acb], [bb-acb]
*/

