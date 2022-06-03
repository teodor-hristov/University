% Member of a list
member(X, [X|_]).
member(X, [_|T]):- member(X, T).

%Merge two lists
append([], X, X).
append([H|T], L2, [H|R]):- append(T, L2, R). 

%Insert X, L ,R
insert(X, L, Res):- append(A,B,L), append(A, [X|B], Res).

%Remove X, L, R
remove(X, [X], []).
remove(X, [X|T], T).
remove(X, [H|T], [H|R]):- remove(X, T, R).

%Subset L1, L2
subSet([],[]).
subSet([_|T], L2):- subSet(T,L2).
subSet([H|T1], [H|T2]):- subSet(T1,T2).

%Permutation
perm([],[]).
perm([H|T], R):- perm(T, Tmp), insert(H, Tmp, R).

%First
first([F|_], F).

%Second
second([_,S|_], S).

%Last
last([E], E).
last([_|T], E):- last(T, E).

%is the first argument a prefix of the second
prefix([], [_]).
prefix([H|T], [H|Tmp]):- prefix(T,Tmp).

%is the first argument a suffix of the second
suffix(S, L):- append(_, S, L).

%SubList
subList([],[]).
subList([],_).
subList([_|T], L2):- prefix(T, L2).
subList([H|T], [H|G]):- prefix(T, G).