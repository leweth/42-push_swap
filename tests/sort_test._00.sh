ARGS="92445434 61000883 -144009862 -48581694 -211261776 -67104645 -13598760 -112284276 160161578 150709801"
ARGS1="201941995 -165376469 202941377 131948324 -125936845 -143281358 -121557905 -202647023 -183455013 -141537994"



./push_swap $ARGS | ./checker_OS $ARGS


./push_swap $ARGS | wc -l

