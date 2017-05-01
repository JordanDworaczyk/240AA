% Jordan Dworaczyk
% CSC240
% Quest

% assign the state that will start the program

start_state(front_line).

% define the edges of the finite state diagram

next_state(front_line, a, no_number_1).
next_state(front_line, b, get_food) :- stored_answer(have_money, yes).
next_state(front_line, b, no_money) :- stored_answer(have_money, no).
next_state(front_line, c, get_food) :- stored_answer(have_money, yes).
next_state(front_line, c, no_money) :- stored_answer(have_money, no).
%next_state(front_line, d, window).

next_state(no_money, a, no_money).
next_state(no_money, b, front_line).
next_state(no_money, c, front_line).

next_state(no_number_1, a, no_food).
next_state(no_number_1, b, get_food) :- stored_answer(have_money, yes).
next_state(no_number_1, b, no_money) :- stored_answer(have_money, no).
next_state(no_number_1, c, get_food) :- stored_answer(have_money, yes).
next_state(no_number_1, c, no_money) :- stored_answer(have_money, no).


% code to be executed at the beginning...

display_intro :-
  write('The journey to Burder King...'), nl, nl,
  write('Alas you have arrived at Burger King...'), nl,
  write('You are hungry and disoriented from the long journey,'), nl,
  write('but now you have reached the position in the line to finally order.'), nl.

initialize :-
  asserta(stored_answer(moves,0)),
  asserta(stored_answer(treasure, 0)),
  asserta(stored_answer(have_money,no)), % was have_key
  asserta(stored_answer(given_money, yes)). % was key_under_doormat

% code to be executed at the end...

goodbye :-
  stored_answer(moves, Count),
  write( 'You made this many moves...' ),
  write( Count ), nl,
  stored_answer(treasure, Amount),
  write( 'You have this many kids toys...'),
  write( Amount ), nl,
  write( 'Have a nice day'), nl.

% code to be executed upon reaching each state

show_state(front_line) :-
  write('You have been waiting for what seems like hours...'), nl,
  write( 'Do you want to...'), nl,
  write('(a) Order Number One'), nl,
  write('(b) Order Number Two'), nl,
  write('(c) Order number Three'), nl,
  write('(q) Quit the program'), nl.

show_state(no_money) :-
  stored_answer(given_money, yes),nl,
  write('Uh oh! You do not have enough money!'), nl,
  write('Do you want to...'), nl,
  write('(a) Look up'), nl,
  write('(b) Go to the back of the line'), nl,
  write('(c) Look behind you'), nl,
  write('(q) Quit the program'), nl.

show_state(no_money) :-
  stored_answer(given_money, no),
  write( 'You are out of luck!'), nl,
  wriite('Do you want to...'), nl,
  write('(b) Go to the back of the line'), nl,
  write('(c) Look up'), nl,
  write('(q) Quit the program'), nl.

show_state(no_number_1) :-
  write( 'Sorry, they are fresh out of number 1s' ), nl,
  write( 'Do you want to...'), nl,
  write('(a) Argue with the King of Burgers'), nl,
  write('(b) Order Number 2'), nl,
  write('(c) Order Number 3 '), nl,
  write('(q) Quit the program'), nl.

% final states do not display a menu - they automatically quit ('q')

show_state(get_food) :-
  write( 'You have your food.'), nl,
  write( 'You may eat.' ), nl.

show_state(no_food) :-
  write( 'The police will be on their way soon'), nl,
  write( 'Maybe you will get food in the holding cell.'),nl.

get_choice(get_food,q).
get_choice(no_food,q).

% code to be executed for each choice of action from each state...

show_transition(front_line, a) :-
  write( 'Excellent choice! You order the number one but...'), nl.
show_transition(front_line, b) :-
   stored_answer(have_money, yes),
   write('Excellent choice! You order a number Two and now you can eat!'), nl.
 show_transition(front_line, b) :-
   stored_answer(have_money, no),
  write('Excellent choice! You order a number two but...'), nl.
show_transition(front_line, c) :-
  stored_answer(have_money, yes),
  write('Excellent choice! You order the number three and now you can eat!'), nl.
show_transition(front_line, c) :-
  stored_answer(have_money, no),
  write('Excellent choice! You order the number three but...'), nl.
% show_transition(front_line, d) :-
 % write('You stumble off to your left in the dark...'), nl.

show_transition(no_money, a) :-
  write( 'A Burger King kid toy falls from the sky!'), nl,
  stored_answer(treasure, Amount),
  retract(stored_answer(treasure,_)),
  NewAmount is Amount + 1,
  asserta(stored_answer(treasure, NewAmount)).
show_transition(no_money, b) :-
  write('You walk all the way back to the end of the line and begin waiting once again.'), nl.
show_transition(no_money, c) :-
  write( 'You see a person behind you. You switch places with the man in the back of the line in retrun for spare change.' ), nl,
  retract(stored_answer(given_money, yes)),
  asserta(stored_answer(given_money, no)),
  retract(stored_answer(have_money,no)),
  asserta(stored_answer(have_money, yes)).

show_transition(no_number_1, a) :-
  write( '...and its all down hill from here!'), nl.
show_transition(no_number_1, b) :-
  write( 'This better be on the menu...'), nl.
show_transition(no_number_1, c) :-
  write('Well, this better end up being on the menu...'), nl.

show_transition(front_line, fail) :-
  write('a,b,c, or q'), nl.
show_transition(no_money, fail) :-
  stored_answer(have_money, yes),
  write('a,b,c, or q'), nl.
show_transition(no_money, fail) :-
  stored_answer( have_money, no),
  write( 'a,b,c or q'), nl.
show_transition(no_number_1, fail) :-
  write( 'a, b, c, or q' ), nl.

% basic finite state machine engine

go :-
  intro,
  start_state(X),
  show_state(X),
  get_choice(X, Y),
  go_to_next_state(X,Y).

intro :-
  display_intro,
  clear_stored_answers,
  initialize.

go_to_next_state(_,q) :-
  goodbye, ! .

go_to_next_state(S1, Cin) :-
  next_state(S1, Cin, S2),
  show_transition(S1, Cin),
  show_state(S2),
  stored_answer(moves, K),
  OneMoreMove is K + 1,
  retract(stored_answer(moves,_)),
  asserta(stored_answer(moves,OneMoreMove)),
  get_choice(S2, Cnew),
  go_to_next_state(S2, Cnew).

go_to_next_state(S1, Cin) :-
  \+ next_state(S1, Cin, _),
  show_transition(S1, fail),
  get_choice(S1, Cnew),
  go_to_next_state(S1, Cnew).

get_choice(_ ,C) :-
  write('Next entry (letter followed by a period)?'),
  read(C).

% case knowledge base - user responses
:- dynamic( stored_answer/2).

% procedure to get rid of previous responses
% without abolishing the dynamic declaration
clear_stored_answers :- retract(stored_answer(_,_)), fail.
clear_stored_answers.
