import random
import time


def toggleTurn(player):
    if player == 1:
        return 2
    else:
        return 1


def minimax(noOfSticks, maximizing, depth, alpha=float("-inf"), beta=float("inf")):

    if depth == 0 or noOfSticks == 0:
        # If we've reached the maximum depth or the game is over, return the score.
        return (noOfSticks, None)

    # Generate all possible moves.
    possible_moves = []
    for i in range(1, 4):
        if noOfSticks >= i:
            possible_moves.append(i)

    # If there are no possible moves, the other player wins.
    if len(possible_moves) == 0:
        return (float("-inf"), None)

    # If the current player is maximizing, find the move with the highest score.
    if maximizing:
        best_move = None
        for move in possible_moves:
            eval, _ = minimax(noOfSticks - move, False, depth - 1, alpha, beta)
            if eval > alpha:
                alpha = eval
                best_move = move
            if alpha >= beta:
                break
        return (alpha, best_move)

    # If the current player is minimizing, find the move with the lowest score.
    else:
        best_move = None
        for move in possible_moves:
            eval, _ = minimax(noOfSticks - move, True, depth - 1, alpha, beta)
            if eval < beta:
                beta = eval
                best_move = move
            if alpha >= beta:
                break
        return (beta, best_move)


def playGame(noOfSticks, noOfPlayer):
    if (noOfPlayer == 1):
        # player-1 is human
        # player-2 is computer
        current_player = 1
        if current_player == 1:
            print("You Won the toss!")
        else:
            print("Computer Won the toss!")
        while noOfSticks > 0:
            print(f"There are {noOfSticks} noOfSticks left.")
            if current_player == 1:
                # Ask the human for their move.
                move = int(
                    input("How many noOfSticks do you want to remove : "))
                while move < 1 or move > 3 or move > noOfSticks:
                    move = int(
                        input("Invalid move. How many noOfSticks do you want to remove? "))
                print()
                print("****************************************************")
                print(f"You removed {move} noOfSticks.")
                print("****************************************************")
                print()
            else:
                # Use the minimax algorithm to determine the computer's move.
                score, move = minimax(noOfSticks, False, 21)
                time.sleep(600/1000)
                print()
                print("****************************************************")
                print(f"The computer removes {move} noOfSticks.")
                print("****************************************************")
                print()
            # Update the game state.
            noOfSticks -= move

            # toggle the turn  of the player
            current_player = toggleTurn(current_player)

        # Game over.
        if current_player == 1:
            print("Congrats! You won")
        else:
            print("Oops! Computer Won")
    else:
        # Both players are human
        current_player = random.randint(1, 2)
        print(f"player {current_player} won the toss")
        while noOfSticks > 0:
            print(f"There are {noOfSticks} noOfSticks left.")
            if current_player == 1:
                # Ask player-1 for their move.
                move = int(
                    input("How many noOfSticks do you want to remove : "))
                while move < 1 or move > 3 or move > noOfSticks:
                    move = int(
                        input("Invalid move. How many noOfSticks do you want to remove? "))
                print(f"Player-1 removed {move} noOfSticks.")
            else:
                # Ask player-2 for their move.
                move = int(
                    input("How many noOfSticks do you want to remove? "))
                while move < 1 or move > 3 or move > noOfSticks:
                    move = int(
                        input("Invalid move. How many noOfSticks do you want to remove? "))
                print(f"Player-2 removed {move} noOfSticks.")

            # Update the game state.
            noOfSticks -= move

            # toggle the turn  of the player
            current_player = toggleTurn(current_player)

        # Game over.
        if current_player == 1:
            print("Congrats! Player-1 Won")
        else:
            print("Congrats! Player-2 Won")


noOfSticks = int(input("Enter Number Of Sticks : "))
playGame(noOfSticks, 1)
