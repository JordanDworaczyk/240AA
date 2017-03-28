% Jordan Dworaczyk
% CSC240AA - Program #10
% Due Wednesday, March 22
% In Prolog, prepare a geneological knowledge base of some historical royal
% family.


% male( <name> ).
male( Werner_I ).
male( Otto_II ).
male( Werner_II ).
male( Louis_I ).
male( Albert_III ).
male( Otto_III ).
male( Rudolph_II ).
male( Albert_IV ).
male(Rudolph_III ).
male( Rudolph_I ).

% female( <name> ).
female( Reginlinde_of_Nellenburg).
female( Hilla_von_Pfirt ).
female( Ida_of_Habsburg ).
female( Richenza ).
female( Ida_of_Pfullendorf ).
female( Agnes_of_Staufen ).
female( Hedwig_of_Kyburg ).

% lifespan( <person's name>, <birth year>, <death year> ).
lifespan( Werner_I, 1030, 1096 ).
lifespan( Otto_II, unkown, 1111 ).
lifespan( Werner_II, unkown, 1167 ).
lifespan( Albert_II, unkown, 1199 ).
lifespan( Rudolph_II, unkown, 1232 ).
lifespan( Albert_IV, 1188, 1239 ).
lifespan( Rudolf_I, 1218, 1291 ).

% parentOf( <parent's name>, <child's name> ).
parentOf( Werner_I, Otto_II ).
parentOf( Reginlinde_of_Nellenburg, Otto_II ).
parentOf( Otto_II , Werner_II  ).
parentOf( Hilla_von_Pfirt, Werner_II).
parentOf( Werner_II, Richenza ).
parentOf( Werner_II, Albert_III ).
parentOf( Werner_II, Otto_III ).
parentOf( Ida_of_Habsburg, Richenza ).
parentOf( Ida_of_Habsburg, Albert_III ).
parentOf( Ida_of_Habsburg, Otto_III ).
parentOf( Albert_III, Rudolph_II).
parentOf( Ida_of_Pfullendorf, Rudolph_II).
parentOf( Rudolph_II, Albert_IV ).
parentOf( Rudolph_II, Rudolph_III).
parentOf( Agnes_of_Staufen, Albert_IV ).
parentOf( Agnes_of_Staufen, Rudolph_III).
parentOf( Albert_IV, Rudolf_I).
parentOf( Hedwig_of_Kyburg, Rudolf_I ).

% rulerOf( <ruler's name>, <country's name>, <year began>, <year ended> ).
rulerOf( Werner_I, Count_of_Habsburg, , ).
rulerOf( Otto_II, Count_of_Habsburg, , ).
rulerOf( Werner_II, Count_of_Habsburg , , ).
rulerOf( Louis_I, Count_of_Pfirt, , ).
rulerOf( Albert_III, Count_of_Habsburg, , ).
rulerOf( Otto_III, Bishop_of_Constance, , ).
rulerOf( Rudolph_II, Count_of_Habsburg, , ).
rulerOf( Albert_IV, Count_of_Habsburg, , ).
rulerOf( Rudolph_III, Count_of_Laufenburg, , ).
rulerOf( Rudolf_I, King_of_Germany, , ).
