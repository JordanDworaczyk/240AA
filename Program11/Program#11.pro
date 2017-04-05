% Jordan Dworaczyk
% CSC240AA - Program #11
% Due Wednesday, March 29
% In Prolog, create definitions for the following rules.

% motherOf( <mother's name>, <child's name> ).
% fatherOf( <father's name>, <child's name> ).
% sonOf( <son's name>, <parent's name> ).
% daughterOf( <daughter's name>, <parent's name> ).
% brotherOf( <brother's name>, <sibling's name> ).h
% sisterOf( <sister's name>, <sibling's name> ).
% siblingOf( <sibling's name>, <sibling's name> ).

% motherOf( <mother's name>, <child's name> ).
motherOf( Person, Child ) :-
  parentOf( Person, Child ),
  female( Person ).

% fatherOf( <father's name>, <child's name> ).
fatherOf( Person, Child ) :-
  parentOf( Person, Child ),
  male( Person ).

% sonOf( <son's name>, <parent's name> ).
sonOf( Person, Parent ) :-
  male( Person ),
  parentOf( Parent, Person ).

% daughterOf( <daughter's name>, <parent's name> ).
daughterOf( Person, Parent ) :-
  female( Person ),
  parentOf( Parent, Person ).

% brotherOf( <brother's name>, <sibling's name> ).
brotherOf( Person, Sibling ) :-
  sonOf( Person, Parent ),
  parentOf( Parent , Sibling ).

% sisterOf( <sister's name>, <sibling's name> ).
sisterOf( Person, Sibling ) :-
  daughterOf( Person, Parent ),
  fatherOf( Parent, Sibling ).

% siblingOf( <sibling's name>, <sibling's name> ).
siblingOf( PersonA, PersonB ) :-
  fatherOf( Parent, PersonA ),
  fatherOf( Parent, PersonB ),
  \+ PersonA = PersonB,
  \+ PersonB = PersonA.

% auntOf( <aunt's name>, <person> ).
auntOf( Aunt, Person ) :-
  parentOf( Parent, Person ),
  sisterOf( Aunt, Parent ).

% grandparentOf( <grandparent's name>, <person's name> ).
grandparentOf( GrandParent, Person ) :-
  parentOf( Parent, Person ),
  parentOf( GrandParent, Parent).

% ancestorOf( <ancestor's name>, <person's name> ).
ancestorOf(Ancestor, Person) :- parentOf(Ancestor, Person).
ancestorOf( Ancestor, Person ) :-
  parentOf( Ancestor, Other ), ancestorOf( Other, Person).

% descendentOf( <descendant's name>, <person's name> ).
descendentOf( Descendent, Person ) :- parentOf( Person, Descendent ).
descendentOf( Descendent, Person ) :-
  parentOf( Person, Other ),
  descendentOf( Descendent, Other ).
