#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece
{
    public:
        King(Team team, std::pair<int, int> pos);
        virtual ~King();

    protected:

    private:
};

#endif // KING_H
