# Features of the Code - Stone Paper Scissors Game 🎮

---

## Core Features

**Multiple Rounds** – The player can choose how many rounds to play, between 1 and 10 rounds.

**Player Choice** – The player selects one of three options: **Paper (1)**, **Stone (2)**, or **Scissor (3)**.

**Computer Choice** – The computer generates a **random choice** using the `rand()` function.

**Round Winner Determination** – The game compares the player's choice against the computer's choice to determine the winner of each round.

**Score Tracking** – The game tracks three statistics: **Player Wins**, **Computer Wins**, and **Draws**.

**Final Game Winner** – After all rounds are completed, the game determines the **overall winner** based on who has the most wins.

**Visual Feedback** – The console changes color to reflect the result:
- **Green** when the player wins
- **Red** when the computer wins
- **Yellow** for a draw

**Sound Effect** – A **beep sound** (`\a`) plays when the computer wins a round.

**Round Details Display** – Each round shows detailed information including both choices and the winner's name.

**Final Results Display** – At the end of the game, a **formatted summary** shows all statistics and the final winner.

**Replay Option** – After the game ends, the player is asked: **"Do You Want to play again?"** with Y/N input.

**Input Validation** – The game validates all user inputs:
- Round count must be between **1 and 10**
- Choice must be between **1 and 3**

---

## Structural Features

**Enums for Readability** – The code uses enumerations for better code clarity:
- `enGameChoice` for **Paper, Stone, Scissor**
- `enWinner` for **Player1, Computer, Draw**

**Struct for Round Data** – `stRoundInfo` stores all information for a single round including: **round number**, **player choice**, **computer choice**, **winner**, and **winner name**.

**Struct for Game Results** – `stGameResults` stores the complete game summary including: **total rounds**, **win counts**, **draw count**, and the **final game winner**.

**Modular Functions** – Each task is handled by a **separate function**, following the Single Responsibility Principle.

**Tab Formatting** – A `Tabs()` function provides **consistent output formatting** throughout the game.

---

## User Experience Features

**Round Counter** – The game displays the **current round number** during gameplay so the player knows their progress.

**Clear Visual Separation** – The output uses **underscores and tabs** for clean, readable display.

**Game Over Screen** – A formatted **"Game Over" banner** appears at the end of the game.

**Winner Announcement** – The final results clearly show the **winner's name** or **"Draw"**.

**Color Coding** – `SetColorForHowWins()` automatically changes the **console color** to indicate the final result.

**Game Over Screen** – Shows a formatted **end-of-game summary** with all statistics.

**Replay Confirmation** – Prompts the user to **play again** with simple Y/N input.

---

## Game Logic Features

**Rule Implementation** – The game correctly implements the classic rules:
- **Paper beats Stone**
- **Stone beats Scissor**
- **Scissor beats Paper**

**Draw Detection** – The game identifies when both the player and computer make the **same choice**, resulting in a draw.

**Winner Name Mapping** – Converts the **enum winner value** to a readable string like "Player1", "Computer", or "No Winner".

**Choice Name Mapping** – Converts the **enum choice value** to a readable string like "Paper", "Stone", or "Scissors".

**Score Comparison** – Compares total wins to determine the **game winner** after all rounds are complete.

**Random Seed Initialization** – Uses `srand(time(NULL))` to ensure **truly random** computer choices each time.

---

## Technical Features

**Header Inclusions** – The code includes necessary headers: `iostream`, `cstdlib`, `cmath`, `ctime`, and `string`.

**Using Namespace** – Uses `using namespace std;` for cleaner code.

**Return Type Functions** – Functions return appropriate types including `short`, `enum`, `string`, and `struct`.

**Void Functions** – Functions that only display output are declared as `void`.

**Pass by Value** – All functions pass parameters **by value**, keeping the code simple and safe.

**Console Color Change** – Uses `system("color")` for visual feedback throughout the game.

**System Pause** – Uses `system("pause")` to keep the console window open after the game ends.

**Loop Control** – Uses **do-while loops** for input validation and the replay mechanism.
