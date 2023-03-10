#include "Pawn.h"
#include <iostream>

Pawn::Pawn(Team team, std::pair<int, int> pos)
    :Piece(team, PAWN, pos)
{
    if(team == WHITE)
    {
        Piece::mSurface = IMG_Load("src/pw.png");
        dy = - 1;
        Default = 6;
    }else
    {
        Piece::mSurface = IMG_Load("src/pb.png");
        dy = + 1;
        Default = 1;
    }
}

void Pawn::calcPossibleMoves(Piece* field[8][8], bool checkCheck)
{
    vector<tuple<int, int, Piece::MoveType>> moves;
    if(mPos.second + dy >= 0 && mPos.second + dy <= 7 && field[mPos.first][mPos.second + dy] == NULL)
    {
        moves = pushMove(moves, tuple<int, int, Piece::MoveType>(mPos.first, mPos.second + dy, NORMAL), getOwnKing(field), field, checkCheck);
    }

    if(mPos.second == Default && field[mPos.first][mPos.second + dy * 2] == NULL)
    {
        moves = pushMove(moves, tuple<int, int, Piece::MoveType>(mPos.first, mPos.second + dy * 2, NORMAL), getOwnKing(field), field, checkCheck);
    }

    if(mPos.first + dy >= 0 && mPos.first + dy <= 7 && mPos.second + dy >= 0 && mPos.second + dy <= 7 && field[mPos.first + dy][mPos.second + dy] != NULL)
    {
        if(field[mPos.first + dy][mPos.second + dy]->getTeam() != mTeam)
            moves = pushMove(moves, tuple<int, int, Piece::MoveType>(mPos.first + dy, mPos.second + dy, NORMAL), getOwnKing(field), field, checkCheck);
    }

    if(mPos.first - dy <= 7 && mPos.first - dy >= 0 && mPos.second + dy >= 0 && mPos.second + dy <= 7 && field[mPos.first - dy][mPos.second + dy] != NULL)
    {
        if(field[mPos.first - dy][mPos.second + dy]->getTeam() != mTeam)
            moves = pushMove(moves, tuple<int, int, Piece::MoveType>(mPos.first - dy, mPos.second + dy, NORMAL), getOwnKing(field), field, checkCheck);
    }
    mPossibleMove = moves;
}
