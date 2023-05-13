def minimax(game_state, maximizing, depth):
    """
    This function implements the minimax algorithm to determine the best move
    for the current player at the given game state.
    """
    if depth == 0 or game_state == 0:
        # If we've reached the maximum depth or the game is over, return the score.
        return (game_state, None)

    # Determine the other player.
    other_player = 1 if player == 2 else 2

    # Generate all possible moves.
    possible_moves = []
    for i in range(1, 4):
        if game_state >= i:
            possible_moves.append(i)

    # If there are no possible moves, the other player wins.
    if len(possible_moves) == 0:
        return (float("-inf"), None)

    # If the current player is maximizing, find the move with the highest score.
    if player == 1:
        best_score = float("-inf")
        best_move = None
        for move in possible_moves:
            score, _ = minimax(game_state - move, other_player, depth - 1)
            if score > best_score:
                best_score = score
                best_move = move
        return (best_score, best_move)

    # If the current player is minimizing, find the move with the lowest score.
    if player == 2:
        best_score = float("inf")
        best_move = None
        for move in possible_moves:
            score, _ = minimax(game_state - move, other_player, depth - 1)
            if score < best_score:
                best_score = score
                best_move = move
        return (best_score, best_move)


