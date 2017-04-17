% expert system for deciding college pathway - main control
start :-
  intro,
  write( 'Answer all questions y for yes or n for no.'), nl,
  clear_stored_answers,
  try_all_possibilities.

try_all_possibilities :-  % backtrack through all
  may_be(D),              % possibilities
  explain(D),
  fail.

try_all_possibilities.    % then succeed with no further action.

% case knowledge base - user responses

:- dynamic (stored_answer/2).

% procedure to get rid of previous response
% withough abolishing the dynamic declaration

clear_stored_answers :- retract(stored_answer(_,_)), fail.
clear_stored_answers.

% procedure to ask the user a question and recieve an
% answer, or retrieve the result if already asked

user_says(Q,A) :- stored_answer(Q,A).

user_says(Q,A) :-
  \+ stored_answer(Q,_),
  nl,nl,
  ask_question(Q),
  get_yes_or_no(Response),
  asserta(stored_answer(Q,Response)),
  Response = A.

% Prompt that obtains a yes or no answers

get_yes_or_no( Result ) :-
  get(Char),      % read a single character
  get0(_),        % consume the return after it
  interpret(Char,Result),
  !.              % cut - only one result.

get_yes_or_no( Result ) :-
  nl,
  write('Type y or n'),
  get_yes_or_no( Result ).

interpret(89, yes).
interpret(121, yes).
interpret(78, no).
interpret(110, no).

% expert system for deciding college pathway - customized additions.

intro :-
  write('This program gives you an idea of the '), nl,
  write('"pathway" that you should take to go to College."'),nl.

% possiblities

may_be( this_does_not_apply ) :-
  user_says(q1,no).

may_be( sign_up_for_ASU ) :-
  user_says(q1, yes),
  user_says(q2, yes),
  user_says(q3, yes).


may_be( sign_up_for_community ) :-
  user_says(q1, yes),
  user_says(q2, yes),
  user_says(q3, no),
  user_says(q4, yes).

may_be( take_the_accuplacer ):-
  user_says(q1, yes),
  user_says(q2, yes),
  user_says(q3, no),
  user_says(q4, no).

may_be( sign_up_for_classes ) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, yes),
  user_says(q6, yes),
  user_says(q7, yes),
  user_says(q8, yes).

may_be( take_the_accuplacer_at_Community_College ) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, yes),
  user_says(q6, yes),
  user_says(q7, yes),
  user_says(q8, no).

may_be( apply_to_ASU) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, yes),
  user_says(q6, yes),
  user_says(q7, no).

may_be( enter_into_community_college) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, yes),
  user_says(q6, no).

may_be(transfer_to_ASU) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, no),
  user_says(q9, yes),
  user_says(q10, yes),
  user_says(q11, yes).


may_be(complete_60_credits) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, no),
  user_says(q9, yes),
  user_says(q10, yes),
  user_says(q11, no).

may_be(sign_up_at_MCC) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, no),
  user_says(q9, yes),
  user_says(q10, no).

may_be(take_the_ac) :-
  user_says(q1, yes),
  user_says(q2, no),
  user_says(q5, no),
  user_says(q9, no).

% Text for the questions

ask_question(q1) :- write('Do you want to graduate fro ASU with '),nl,
  write('a bachelors degree?'),nl.

ask_question(q2) :- write('Are you in high school? '),nl.

ask_question(q3) :-
  write('Have you been accepted to ASU? '),nl.

ask_question(q4) :-
  write('Have you taken the accuplacer at Community College? '),nl.

ask_question(q5) :-
  write('Do you have a high school diploma? '),nl.

ask_question(q6) :-
  write('Do you have any college credits? '),nl.

ask_question(q7) :-
  write('Have you applied to ASU? '),nl.

ask_question(q8) :-
  write('Were you accepted? '),nl.

ask_question(q9) :-
  write('Have you taken the accuplacer? '),nl.

ask_question(q10) :-
  write('Have you signed up for classes? '),nl.

ask_question(q11) :-
  write('Have you completed 60 credit hours at community college? '),nl.

% Explanations for the various diagnoses

explain(this_does_not_apply) :- nl,
  write('This does not apply to you.'), nl.

explain(sign_up_for_ASU) :- nl,
  write('Sign up for classes at ASU!'), nl.

explain(sign_up_for_community) :- nl,
  write('Sign up for Community College!'), nl.

explain(take_the_accuplacer) :- nl,
  write('Take the accuplacer at Community College.'), nl.

explain(sign_up_for_classes) :- nl,
  write('Well sign up for some classes then!'), nl.

explain(take_the_accuplacer_at_Community_College) :- nl,
  write('Take the accuplacer test at a community college!'), nl.

explain(apply_to_ASU) :- nl,
  write('Apply to ASU!'), nl.

explain(enter_into_community_college) :- nl,
  write('Find a community college!'), nl.

explain(transfer_to_ASU) :- nl,
  write('Transfer to ASU!'), nl.

explain(complete_60_credits) :- nl,
  write('Complete 60 credit hours at community college!'), nl.

explain(sign_up_at_MCC) :- nl,
  write('Sign up at MCC!'), nl.

explain(take_the_ac) :- nl,
  write('Take the accuplacer at MCC!'), nl.
