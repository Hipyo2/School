%Nicholas Ang
%CS326 Hw 7
%Prolog

%Question 1
%reverseList(L,L1).
reverseList([],[]).
reverseList([H|T], L) :- reverseList(T, L1),append(L1,[H],L).


%Question 2
take([],_,[]).
take([_|_], 0, []).
take([H|_], 1, [H]).
take([H|T], N, L1) :- N>=0, N2 is N-1,take(T,N2,L2),append([H],L2,L1).


%Question 3
%Given Tree Definitions
tree(nil).
tree(node(_,Left,Right)) :- tree(Left), tree(Right).

%Q3a.
%nleaves(T,N).
nleaves(nil, 0).
nleaves(node(_,nil,nil), 1).
nleaves(node(_,Left,Right),N) :- nleaves(Left,N1), nleaves(Right,N2), N is N1+N2.

%Q3b.
%treeMember(E,T).
treeMember(E, node(E,nil,nil)).
treeMember(E, node(E,_,_)).
treeMember(E, node(_,Left,_)) :- treeMember(E, Left).
treeMember(E, node(_,_,Right)) :- treeMember(E, Right).

%Q3c.
%preOrder(T,L).
preOrder(nil,[]).
preOrder(node(X,nil,nil), [X]).
preOrder(node(X,Left,Right), L) :- preOrder(Left,L1), preOrder(Right,L2), append([X],L1,L3), append(L3,L2,L).

%Q3d.
%height(T,N).
height(nil,0).
height(node(_,nil,nil),1).
height(node(_,Left,Right), N) :- height(Left,N1),height(Right,N2), N is max(N1,N2) + 1.


%Question 4
%insert(X,L,L1).
%assume already sorted
insert(N, [], [N]).
insert(N, [H|T], L1):- N =< H, append([N],[H|T], L1).
insert(N, [H|T], L1):- N > H, insert(N, T,L2), append([H], L2, L1).


%Question 5 - EXTRA CREDIT
%flattenList(A,B).
flattenList([], []).
flattenList([H],[H]).
flattenList([H|T],L1) :- flattenList(H,L2),flattenList(T,L3), append(L2,L3,L1).
flattenList([[H|T1]|T2], L1):- append([H|T1],T2,L1).
flattenList([[H]|T2], L1):- append(H,T2,L1).
flattenList([H|[H2|T2]],L1) :- flattenList([H2|T2],L2), append([H],L2,L1).
flattenList([H|[T2]],L1) :- flattenList([T2],L2), append([H],L2,L1).
