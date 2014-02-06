#ifndef TOWEROFHANOIVIEW_H
#define TOWEROFHANOIVIEW_H





/*****
 * This is the main class which is responsible for managing the
 * scene and controlling the game. All game logic will be performed
 * from this class
 *
 * ***/


#include <QTimer>


#include <QtMath>
#include <QList>
#include <QFont>
#include <QDebug>
#include <QLabel>
#include <QString>
#include <QSpinBox>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QMessageBox>

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

/*Our Graphics Items*/
#include "disc.h"
#include "tower.h"
#include "tobjects.h"

class TowerofHanoiView : public QGraphicsView{

    Q_OBJECT

    private:
        /*Attributes*/
        QPushButton *btn_start;
        QPushButton *btn_reset;
        QPushButton *btn_pause;



        QGraphicsTextItem * text_number_of_disc;
        QSpinBox * spin_number_of_disc;
        QList<QPushButton*> *btn_list;

        qreal button_spacing;
        qreal button_height;
        qreal button_width;

        bool is_startrted;
        bool is_paused;
        bool is_reset;
        bool is_game_finished;

        QFont *tFont;

        /*Attributes*/
        QGraphicsScene *scene_tower_of_hanoi_scene;

        int MaximumDisc;
        Tower *tower_a;
        int tower_a_pos_x;
        int tower_a_pos_y;

        Tower *tower_b;
        int tower_b_pos_x;
        int tower_b_pos_y;

        Tower *tower_c;
        int tower_c_pos_x;
        int tower_c_pos_y;

        QPushButton *tower_a_switch;
        QPushButton *tower_b_switch;
        QPushButton *tower_c_switch;


        int move_counter;
        int press_counter;

        OMoveCounter *move_viewer;
        OMinMoveCounter *min_move_viewer;

        /*Two Press Counter*/
        int move_start_tower;
        int move_end_tower;


        QTimer *animation_timer;
        int now_animating;





    public:
        TowerofHanoiView();
        void rePositionItems();
        void rePositionAll();

        void ResetSystem();


        void MoveToTower(Tower *a,Tower *b);
        void StartMoving();
        void GameFinishedStartNew();

        vector < pair < Tower * , Tower * > > V;
        void solveGame(int tot,Tower *s,Tower *d,Tower *a);





    private:
        QPushButton * createButton(QString label,int width,int height);

    public slots:
        void StartPressed();
        void PausePressed();
        void ResetPressed();

        void SetMaximumDisc(int n);

        void TowerA_pressed();
        void TowerB_pressed();
        void TowerC_pressed();


        void SolverAnimation();


    protected:
        void mousePressEvent(QMouseEvent *event);
        void resizeEvent(QResizeEvent *);



};

#endif // TOWEROFHANOIVIEW_H
