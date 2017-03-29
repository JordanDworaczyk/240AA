% Jordan Dworaczyk
% CSC240AA - Program #10
% Due Wednesday, March 22
% In Prolog, prepare a geneological knowledge base of some historical royal
% family.


% male( <name> ).
male( werner_I ).
male( otto_II ).
male( werner_II ).
male( louis_I ).
male( albert_III ).
male( otto_III ).
male( rudolph_II ).
male( albert_IV ).
male(ruldolph_III ).
male( rudolph_I ).

% female( <name> ).
female( reginlinde_of_Nellenburg).
female( hilla_von_Pfirt ).
female( ida_of_Habsburg ).
female( richenza ).
female( ida_of_Pfullendorf ).
female( agnes_of_Staufen ).
female( hedwig_of_Kyburg ).

% lifespan( <person's name>, <birth year>, <death year> ).
lifespan( werner_I, 1030, 1096 ).
lifespan( otto_II, unknown, 1111 ).
lifespan( werner_II, unknown, 1167 ).
lifespan( albert_II, unknown, 1199 ).
lifespan( rudolph_II, unknown, 1232 ).
lifespan( albert_IV, 1188, 1239 ).
lifespan( rudolf_I, 1218, 1291 ).

% parentOf( <parent's name>, <child's name> ).
parentOf( werner_I, otto_II ).
parentOf( reginlinde_of_Nellenburg, otto_II ).
parentOf( otto_II , werner_II  ).
parentOf( hilla_von_Pfirt, werner_II).
parentOf( werner_II, richenza ).
parentOf( werner_II, albert_III ).
parentOf( werner_II, otto_III ).
parentOf( ida_of_Habsburg, richenza ).
parentOf( ida_of_Habsburg, albert_III ).
parentOf( ida_of_Habsburg, otto_III ).
parentOf( albert_III, rudolph_II).
parentOf( ida_of_Pfullendorf, rudolph_II).
parentOf( rudolph_II, albert_IV ).
parentOf( rudolph_II, rudolph_III).
parentOf( agnes_of_Staufen, albert_IV ).
parentOf( agnes_of_Staufen, rudolph_III).
parentOf( albert_IV, rudolf_I).
parentOf( hedwig_of_Kyburg, rudolf_I ).

% rulerOf( <ruler's name>, <country's name>, <year began>, <year ended> ).
rulerOf( werner_I, count_of_Habsburg, 1045 , 1096 ).
rulerOf( otto_II, count_of_Habsburg, 1096, 1111 ).
rulerOf( werner_II, count_of_Habsburg, 1111, 1167 ).
rulerOf( louis_I, count_of_Pfirt, unknown , unknown ).
rulerOf( albert_III, count_of_Habsburg, 1167, 1199 ).
rulerOf( otto_III, bishop_of_Constance, 1166 , 1174 ).
rulerOf( rudolph_II, count_of_Habsburg, 1199, 1232 ).
rulerOf( albert_IV, count_of_Habsburg, 1232, 1239 ).
rulerOf( rudolph_III, count_of_Laufenburg, 1232, 1249).
rulerOf( rudolf_I, king_of_Germany, 1273, 1291 ).
