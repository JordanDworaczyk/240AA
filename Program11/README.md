###### In Prolog, create definitions for the following rules:

`motherOf( <mother's name>, <child's name> ).`   
`fatherOf( <father's name>, <child's name> ).`   
`sonOf( <son's name>, <parent's name> ).`  
`daughterOf( <daughter's name>, <parent's name> ).`  
`brotherOf( <brother's name>, <sibling's name> ).`h  
`sisterOf( <sister's name>, <sibling's name> ).`  
`siblingOf( <sibling's name>, <sibling's name> ).`  

as well as similar rules for...
> auntOf  
> grandparentOf   
> ancestorOf  
> descendentOf  

###### Also, add the following:   

`contemporaryOf( <person>, <contemporary> ). % alive at the same time`  
`successorOf( <ruler>, <next ruler> ). % immediate successor on the throne`  

### Implementation
Remember, _rules_ may include variables, and state logical inferences or
conclusions.
###### For example:
```Prolog
isBoss( A, B )
  :- employee( A , manager, Company, Department ),
     employee(B, _, Company, Department ).
```  
Translated to English this means:
> _If_ person _'A'_ is a manager and _'B'_ is any employee in the same
_'Company'_ and _'Department'_, then _A_ is the boss of _B_.

Write _rules_ that form relations between the different facts provided in the
knowledge base that you created.

## My Family tree
This is the family that I chose.
![Habsburg Family](FamilyTree.png)
