# Project 1 : En regnemaskine på kommandolinjen
- Programmet afleveres: 26.10.2022 kl. 21.00
- Aflevering: Sidste commit inden deadline der er pushet til Github tæller

# Beskrivelse
Skriv et program der modellerer en simpel regnemaskine. 
Regnemaskinen holder styr på ét enkelt tal af typen `double`, som indholder det hidtidigt beregnede resultat. 
Dette tal kaldes akkumulatoren. 
Akkumulatorens startværdi er `0.0`. 
I en simpel, iterativ dialog med brugeren udføres der forskellige beregninger på akkumulatoren. 
Disse beregninger kan være styret af unære eller binære operatorer, som i denne opgave alle noteres med netop ét tegn.

Unære operationer (som står foran sin operand, og derfor er prefix) udfører en beregning på akkumulatoren:

`operator` `akkumulator`

Binære operationer udfører en beregning på akkulatoren og en ekstra operand på følgende måde:

`akkumulator` `operator` `højre_opperand`

I begge tilfælde lægges værdien af udtrykket tilbage i akkumulatoren.

Det anbefales at operationen, som regnemaskinen skal udføre, indlæses som en `char` med `scanf`. 
Binære operatorer kræver en (højre) operand, der indlæses som en `double` med `scanf`.

Du skal have en funktion, `scan_data`, med to output parametre, som returnerer en operator og en mulig højre operand fra en datalinje. 
Hvis der anvendes en unær operator returneres operanden blot som `0.0`.

Du skal også have en funktion, `do_next_op`, som udfører den påkrævede operation: `do_next_op` skal have to input parametre (operator og operand) foruden akkumulatoren, som både skal kunne bruges til input og output (og som derfor skal være en pointer). 
Operanden ignoreres for unære operatorer.

Regnemaskinens samlede dialog skal indkapsles i en funktion, `run_calculator`, som skal returnere slutværdien af akkumulatoren.

Overvej også at skrive en boolsk funktion, der kan afgøre om en operator (af typen `char`) er binær.

Her er de gyldige binære operatorer i regnemaskinen:

- `+`    for addition af akkumulatoren med operanden
- `-`    for subtraktion af akkumulatoren med operanden
- `*`    for multiplikation af akkumulatoren med operanden
- `/`    for division af akkumulatoren med operanden
- `^`    for potensopløftning af akkumulatoren med operanden

Og her er de gyldige unære operatorer:

- `#`    for kvadratroden af akkumulatoren
- `%`    for at vende fortegnet af akkumulatoren
- `!`    for at dividere 1 med akkumulatoren
- `q`    for at afslutte regnemaskinen med slutresultatet

Din regnemaskine skal nægte at tage kvadratroden af et negativt tal, og den skal nægte at dividere med nul. 
I tilfælde af en sådan ulovlig operation, skal akkumulatoren blot efterlades uændret. 
Der skal ikke udskrives fejlmeddelelser.

Din regnemaskine skal vise den akkumulerede værdi efter hver operation.

Her er et eksempel på en dialog med regnemaskinen - som dialogen kan se ud når du får skrevet dit program:

```shell
Enter operator, and an optional operand: + 5.000000
Result so far is 5.000000.
Enter operator, and an optional operand: - 6.000000
Result so far is -1.000000.
Enter operator, and an optional operand: * 3.000000
Result so far is -3.000000.
Enter operator, and an optional operand: #
Result so far is -3.000000.
Enter operator, and an optional operand: %
Result so far is 3.000000.
Enter operator, and an optional operand: #
Result so far is 1.732051.
Enter operator, and an optional operand: ^ 2.000000
Result so far is 3.000000.
Enter operator, and an optional operand: * 4.000000
Result so far is 12.000000.
Enter operator, and an optional operand: !
Result so far is 0.083333.
Enter operator, and an optional operand: q
Final result is: 0.083333
```

Denne opgave er inspireret af en tilsvarende opgave fra 6. og 7. udgave af lærebogen, som anvendes på kurset.

Som altid skal du lave top-down programmering med trinvis forfinelse. 
Overvej omhyggeligt de anvendte kontrolstrukturer. 
Overvej også god brug af operatorerne i C, til at udføre regnemaskinens operationer. 
Og sidst men ikke mindst, brug gode input- og output parametre i dine funktioner.