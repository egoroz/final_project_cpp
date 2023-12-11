#ifndef GAMESTATUS_H
#define GAMESTATUS_H

enum status {Menu, Play, Results};

class GameStatus{
private:
    status stat;
public:
    GameStatus(){
        stat = Menu;
    }

    status GetGameStatus(){
        return stat;
    }

    void ChangeGameStatus(status st_){
        stat = st_;
    }
};

#endif //GAMESTATUS_H