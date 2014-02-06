#include "towerofhanoiview.h"

/* Game Controlled From:
 *   TowerA_pressed()
 *   TowerB_pressed()
 *   TowerC_pressed()
 *
 * MoveMent Done By:
 *      StartMoving()
 *          MoveToTower(Tower *a,Tower *b)
 *
 * If You need any modification of the logic you need to modify avobe methods
*/




TowerofHanoiView::TowerofHanoiView()
{
    this->setWindowTitle("Tower of Hanoi");
    this->setFixedSize(620,620); /* Setting The Size of The Window */
    this->setBackgroundBrush(QColor(230, 200, 167));
    this->MaximumDisc = 3; /* Initilize How Many Discs will be shown when the game first started*/



    /*Adding a Scene into the View*/
    this->scene_tower_of_hanoi_scene = new QGraphicsScene();   /*Every Graphics View needs a Graphics Scene to manage all graphics item*/
    this->setScene(this->scene_tower_of_hanoi_scene);

    /*Rendering Options*/
    this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform); /*Don't nedd to see now if you are not familiar with it. It is just a message to the Graphics rendering Engine of Qt*/
    this->setCacheMode(QGraphicsView::CacheBackground);
    this->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);   /*How the update procedure will be performed. Every single change to the graphics item need to be updated to show the update*/



    /*This is a Container of our all available buttons such as start,reset,pause. It is used to managge the position of the buttons on the view*/
    btn_list = new QList<QPushButton*>();

    this->button_spacing = 3;
    this->button_height = 20;
    this->button_width = 50;

    /*Which Font Will be Used For Writing text into the view*/
    tFont = new QFont("Times New Roman");
    tFont->setBold(false);
    tFont->setPointSize(10);





    /*Just The Text Before the Disk number spinner*/
    this->text_number_of_disc = new QGraphicsTextItem();
    this->text_number_of_disc->setFont(*tFont);
    this->text_number_of_disc->setPlainText("Discs:");
    this->scene_tower_of_hanoi_scene->addItem(this->text_number_of_disc);

    /*Creating Disk Number Spinner.By using this a user can change the Maximum Number of discs*/
    this->spin_number_of_disc = new QSpinBox();
    this->spin_number_of_disc->setToolTip("Maximum Number of Discs");
    this->spin_number_of_disc->setValue(3);
    this->spin_number_of_disc->setMinimum(3);
    this->spin_number_of_disc->setMaximum(12);
    this->scene_tower_of_hanoi_scene->addWidget(this->spin_number_of_disc);
    /*Connecting spin change to a method. This method will update the maximum
     * disc number and reset the reset*/
    connect(spin_number_of_disc,
            SIGNAL( valueChanged(int) ),
            this,
            SLOT(SetMaximumDisc(int)) );





    /*Creating Buttons*/
    btn_start = this->createButton("START",button_width,button_height); /*Not used now. will be used in future*/
    this->btn_list->append(btn_start);
    //this->scene_tower_of_hanoi_scene->addWidget(btn_start); //uncomment it to make visible into the scene

    btn_pause = this->createButton("PAUSE",button_width,button_height); /*Not used now. will be used in future*/
    this->btn_list->append(btn_pause);
    //this->scene_tower_of_hanoi_scene->addWidget(btn_pause);

    btn_reset = this->createButton("RESET",button_width,button_height);
    btn_reset->setStyleSheet("border-color: rgb(85, 170, 255);border-top-color: rgb(85, 85, 255);");
    btn_reset->update();
    this->btn_list->append(btn_reset);

    this->scene_tower_of_hanoi_scene->addWidget(btn_reset);
    this->scene_tower_of_hanoi_scene->addWidget(btn_start);


    /*Connect button press with a method*/
    connect(btn_start,
            SIGNAL(pressed()),
            this,
            SLOT(StartPressed()));
    connect(btn_pause,
            SIGNAL(pressed()),
            this,
            SLOT(PausePressed()));
    connect(btn_reset,
            SIGNAL(pressed()),
            this,
            SLOT(ResetPressed()));



    /*Initializing The Three Towers A,B,C*/
    tower_a = new Tower(1);
    tower_b = new Tower(2);
    tower_c = new Tower(3);

    /*Adding the Towers into the scene*/
    this->scene()->addItem(tower_a);
    this->scene()->addItem(tower_b);
    this->scene()->addItem(tower_c);

    /*Tower Click Button*/
    this->tower_a_switch = this->createButton("A",180,30); /*Tower A press switch*/
    this->tower_b_switch = this->createButton("B",180,30); /*Tower B press switch*/
    this->tower_c_switch = this->createButton("C",180,30);/*Tower C press switch*/

    /**Connecting Switches into a Method/Slot.When a press is performed what will be done
     * is Defined into that Method. Actually All the Logic and Movement controlled from there
     **/
    connect(tower_a_switch,
            SIGNAL(pressed()),
            this,
            SLOT(TowerA_pressed()));
    connect(tower_b_switch,
            SIGNAL(pressed()),
            this,
            SLOT(TowerB_pressed()));
    connect(tower_c_switch,
            SIGNAL(pressed()),
            this,
            SLOT(TowerC_pressed()));

    /*Adding Towers switch into The Scene*/
    this->scene()->addWidget(this->tower_a_switch);
    this->scene()->addWidget(this->tower_b_switch);
    this->scene()->addWidget(this->tower_c_switch);















    this->move_viewer = new OMoveCounter();
    this->scene()->addItem(this->move_viewer);

    this->min_move_viewer = new OMinMoveCounter();
    this->scene()->addItem(this->min_move_viewer);





    this->tower_a_pos_x = 20;
    this->tower_a_pos_y = this->width() - tower_a->boundingRect().height() - 100;

    this->tower_b_pos_x = this->tower_a_pos_x + 1*tower_a->boundingRect().width()+1*20;
    this->tower_b_pos_y = this->tower_a_pos_y;
    this->tower_c_pos_x = this->tower_a_pos_x + 2*tower_a->boundingRect().width()+2*20;
    this->tower_c_pos_y = this->tower_a_pos_y;


    tower_a->setPos( this->tower_a_pos_x , this->tower_a_pos_y );
    this->tower_a_switch->move(this->tower_a_pos_x,this->height() - 100);

    tower_b->setPos( this->tower_b_pos_x , this->tower_b_pos_y);
    this->tower_b_switch->move(this->tower_b_pos_x,this->height() - 100);

    tower_c->setPos( this->tower_c_pos_x , this->tower_c_pos_y );
    this->tower_c_switch->move(this->tower_c_pos_x,this->height() - 100);


    this->scene_tower_of_hanoi_scene->setSceneRect(0, 0, this->width()-5, this->height()-5);
    this->rePositionItems();



    this->ResetSystem();

    animation_timer = new QTimer(this);
    connect(animation_timer,
            SIGNAL(timeout()),
            this,
            SLOT(SolverAnimation() ) );

}




void TowerofHanoiView::ResetSystem(){

    this->now_animating = 0;

    this->is_game_finished = false;
    this->press_counter = 0;
    this->move_counter = 0;
    this->move_end_tower = 0;
    this->move_start_tower = 0;

    this->move_viewer->setMoves(this->move_counter);
    /*default Switch Values*/
    this->is_startrted = true;
    this->is_paused = false;
    this->is_reset = false;

    this->min_move_viewer->setMoves( pow(2.0,MaximumDisc) - 1);

    tower_a->RemoveAll();
    tower_b->RemoveAll();
    tower_c->RemoveAll();

    Disc *n1;
    for(int i=this->MaximumDisc;i>0;i--){
       n1 = new Disc(i);
       tower_a->addToTop(n1);
   }





}



void TowerofHanoiView::rePositionAll(){
    this->rePositionItems();
}

void TowerofHanoiView::rePositionItems(){
    /*This Method Will Re position all button according to scene retangular size*/

    //qreal width = this->sceneRect().width();
    qreal height = this->sceneRect().height();
    qreal start_position_x = 5;

    qreal x_pos = start_position_x;
    qreal y_pos = height - this->button_height - this->button_spacing;

    for(int i = 0;i <this->btn_list->count();i++){
        this->btn_list->at(i)->move(x_pos,y_pos);
        x_pos = x_pos + this->button_width + this->button_spacing;
        }

    //x_pos = x_pos +20;
    this->text_number_of_disc->setPos(x_pos,y_pos);

    x_pos = x_pos + 40;
    this->spin_number_of_disc->move(x_pos,y_pos);

    //this->min_move_viewer->setPos(0,this->move_viewer->boundingRect().height());
    this->min_move_viewer->setPos(this->width() - this->min_move_viewer->boundingRect().width() - 100,this->height() - this->min_move_viewer->boundingRect().height() );

    }


QPushButton * TowerofHanoiView::createButton(QString label, int width, int height){
    /*helper method to shorten button cration*/
    QPushButton *button = new QPushButton(label);
    button->setFixedSize(width,height);
    return button;

}





void TowerofHanoiView::resizeEvent(QResizeEvent *)
{
    //qDebug() << "Inside TowerofHanoiView :" << event;
    this->scene_tower_of_hanoi_scene->setSceneRect(0, 0, this->width()-5, this->height()-5);
    //this->rePositionAll();

}


void TowerofHanoiView::mousePressEvent(QMouseEvent *event){
    //qDebug() << "TowerofHanoiView Clicked:"<<event;
    QGraphicsView::mousePressEvent(event);
    //this->tower_a->mousePressEvent(event);

}





/***
 *
 * Game Logic
 *
 *
 */

void TowerofHanoiView::StartMoving(){
    if (this->move_start_tower == 1 && this->move_end_tower == 2) this->MoveToTower(this->tower_a , this->tower_b);
    else if (this->move_start_tower == 2 && this->move_end_tower == 1) this->MoveToTower(this->tower_b , this->tower_a);

    else if (this->move_start_tower == 1 && this->move_end_tower == 3) this->MoveToTower(this->tower_a , this->tower_c);
    else if (this->move_start_tower == 3 && this->move_end_tower == 1) this->MoveToTower(this->tower_c , this->tower_a);

    else if (this->move_start_tower == 2 && this->move_end_tower == 3) this->MoveToTower(this->tower_b , this->tower_c);
    else if (this->move_start_tower == 3 && this->move_end_tower == 2) this->MoveToTower(this->tower_c , this->tower_b);


    //qDebug()<<"Total Moves:"<<this->move_counter;
    if (this->tower_c->getTotalDisc() == this->MaximumDisc) this->is_game_finished = true;
    if(this->is_game_finished) this->GameFinishedStartNew();


}


void TowerofHanoiView::MoveToTower(Tower *a,Tower *b){
    //int delay=100000000;
    //while(delay--);
    Disc *temp_a = a->getTop();
    Disc *temp_b = b->getTop();

    if (temp_a!=NULL){
        if (temp_b == NULL ){
            a->removeTop();
            b->addToTop(temp_a);
            this->move_counter++;
            this->move_viewer->setMoves(this->move_counter);
        }
        else{
            if( temp_a->getDiscNumber() < temp_b->getDiscNumber() ){
                a->removeTop();
                b->addToTop(temp_a);
                this->move_counter++;
                this->move_viewer->setMoves(this->move_counter);
            }
        }


    }

}







/*****All Slots Definition Goes Here*******/

void TowerofHanoiView::TowerA_pressed(){
    if(!this->is_game_finished){

        if (this->move_start_tower !=  1 && this->move_end_tower != 1) this->press_counter++;
        else this->press_counter = 1;
        //qDebug()<<this->press_counter;

        if (this->press_counter == 1) this->move_start_tower = 1;
        else if (this->press_counter == 2) this->move_end_tower = 1;

        this->StartMoving();

        if(this->press_counter == 2) {
            this->press_counter = 0;
            this->move_start_tower = 0;
            this->move_end_tower = 0;
        }
    }


}



void TowerofHanoiView::TowerB_pressed(){
    if(!this->is_game_finished){
        if(this->press_counter != 0 || this->tower_b->hasDisc()){
            if (this->move_start_tower !=  2 && this->move_end_tower != 2) this->press_counter++;
        }
        if (this->move_start_tower ==  2 && this->move_end_tower == 2) this->press_counter = 1;


    //qDebug()<<this->press_counter;

    if (this->press_counter == 1) this->move_start_tower = 2;
    else if (this->press_counter == 2) this->move_end_tower = 2;


    this->StartMoving();


    if(this->press_counter == 2) {
        this->press_counter = 0;
        this->move_start_tower = 0;
        this->move_end_tower = 0;
    }
    }


}





void TowerofHanoiView::TowerC_pressed(){

    if(!this->is_game_finished){
        if(this->press_counter != 0 || this->tower_c->hasDisc()){
            if (this->move_start_tower !=  3 && this->move_end_tower != 3) this->press_counter++;
        }
        if (this->move_start_tower ==  3 && this->move_end_tower == 3) this->press_counter = 1;

    //qDebug()<<this->press_counter;

    if (this->press_counter == 1) this->move_start_tower = 3;
    else if (this->press_counter == 2) this->move_end_tower = 3;

    this->StartMoving();


    if(this->press_counter == 2) {
        this->press_counter = 0;
        this->move_start_tower = 0;
        this->move_end_tower = 0;
    }
    }


}


void TowerofHanoiView::GameFinishedStartNew(){
    QMessageBox::StandardButton reply;
    QString msg("You have finished the Game with ");
    QString num;

    msg = msg + num.setNum(this->move_counter) + " Moves." + "\nDo You Want to start a New Game?";

    reply = QMessageBox::question(this,
                                  tr("Game Finished"),
                                  msg,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if (reply == QMessageBox::Yes) this->ResetSystem();
    //else if (reply == QMessageBox::No);
    //else;
}



void TowerofHanoiView::SetMaximumDisc(int n){
    this->MaximumDisc = n;
    this->ResetSystem();
}




// Solver
void TowerofHanoiView::solveGame(int tot,Tower *s,Tower *d,Tower *a)
{
    if( tot == 0 ) return;
    solveGame(tot-1,s,a,d);

    //MoveToTower(s,d);
    V.push_back( make_pair ( s , d ) );
    solveGame(tot-1,a,d,s);
}



/*Animation Will be Started from StartPressed*/
void TowerofHanoiView::SolverAnimation(){

    if (this->now_animating<(int) V.size()) {
        MoveToTower( V[this->now_animating].first , V[this->now_animating].second );
        this->now_animating++;
    }
    else{
        this->animation_timer->stop();
    }

}




void TowerofHanoiView::StartPressed(){

    V.clear();
    solveGame(this->MaximumDisc,tower_a,tower_c,tower_b);
    this->animation_timer->start(1000/1); //1 Frame/Sec

    //qDebug()<<"Start Pressed";
}


void TowerofHanoiView::PausePressed(){
}


void TowerofHanoiView::ResetPressed(){
    this->ResetSystem();
}
