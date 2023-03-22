#include <iostream> //cin cout
#include <conio.h> //menginputkan key khusus
#include <time.h> //untuk menginput nilai random pada posisi angka
#include <windows.h> //untuk mengubah warna character
#include <math.h> // untuk menggunakan rumus logaritma
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define EXIT 27
#define KEY_BACKSPACE 8
#define RESET 83
using namespace std;
struct datagame{
    int score=0;
    datagame *next;
}*head=NULL,*tail=NULL,*current=NULL,*newNode=NULL;
int games[4][4];
int backup_games[4][4];
int backup_score;
bool flag[4][4];
void createPlayer(){
    if(head!=NULL){
        newNode = new datagame();
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }else{
        head = new datagame();
        head->next = NULL;
        tail = head; 
    }
}
void randomPosition(){
    int baris,kolom;
    srand(time(0));
    do
    {
        baris=0+rand()%4;
        kolom=0+rand()%4;
    }while (games[baris][kolom]>=2);
    games[baris][kolom]=2;
}
void resetflag(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            flag[i][j]=false;
        }
    }
}
void arrow_up(){
    bool movement=false;
    for (int i = 0; i < 4; i++){
        for (int j = 1; j < 4; j++){
            for(int k=j; k>=1; k--){
                if(k-1>=0){
                    if(games[k-1][i]==0){
                        games[k-1][i]=games[k][i];
                        games[k][i]=0;
                        if (games[k-1][i]!=0)
                        {
                            movement=true;
                        }   
                    }else if (games[k][i]==games[k-1][i]){
                        if ((flag[k-1][i]==false&&flag[k][i]==false)||flag[k][i]==false)
                        {
                            games[k-1][i]+=games[k][i];
                            tail->score+=games[k-1][i];
                            games[k][i]=0;
                            flag[k-1][i]=true; 
                            flag[k][i]=true; 
                            movement=true;
                        }     
                    }  
                }
            }
        }
    }
    resetflag();
    if(movement==true)
    {
        randomPosition();
    }
}
void arrow_down(){
    bool movement=false;
    for (int i = 0; i < 4; i++){
        for (int j = 2; j > -1; j--){
            for(int k=j; k<=3; k++){
                if(k+1<=3){
                    if(games[k+1][i]==0){
                        games[k+1][i]=games[k][i];
                        games[k][i]=0;
                        if (games[k+1][i]!=0){
                            movement=true;
                        }
                        
                    }else if (games[k][i]==games[k+1][i]){
                        if ((flag[k+1][i]==false&&flag[k][i]==false)||flag[k][i]==false)
                        {
                            games[k+1][i]+=games[k][i];
                            tail->score+=games[k+1][i];
                            games[k][i]=0;
                            flag[k+1][i]=true;
                            flag[k][i]=true;
                            movement=true;
                        }
                    }                  
                }
            }
        }
    }
    resetflag();
    if (movement==true)
    {
        randomPosition();
    }
}
void arrow_left(){
    bool movement=false;
    for (int i = 0; i < 4; i++){
        for (int j = 1; j < 4; j++){
            for(int k=j; k>=1; k--){
                if(k-1>=0){
                    if(games[i][k-1]==0){
                        games[i][k-1]=games[i][k];
                        games[i][k]=0;
                        if(games[i][k-1]!=0){
                            movement=true;
                        }
                    }else if (games[i][k]==games[i][k-1]){
                        if ((flag[i][k-1]==false&&flag[i][k]==false)||flag[i][k]==false)
                        {
                            games[i][k-1]+=games[i][k];
                            tail->score+=games[i][k-1];
                            games[i][k]=0;
                            flag[i][k-1]=true;
                            flag[i][k]=true;
                            movement=true;
                        }                   
                    }
                }
            }
        }
    }
    resetflag();
    if(movement==true){
        randomPosition();
    }
}
void arrow_right(){
    bool movement=false;
    for (int i = 0; i < 4; i++){
        for (int j = 2; j > -1; j--){
            for(int k=j; k<=3; k++){
                if(k+1<=3){
                    if(games[i][k+1]==0){
                        games[i][k+1]=games[i][k];
                        games[i][k]=0;
                        if (games[i][k+1]!=0){
                            movement=true;    
                        }                        
                    }else if (games[i][k]==games[i][k+1]){
                        if ((flag[i][k+1]==false&&flag[i][k]==false)||flag[i][k]==false)
                        {
                            games[i][k+1]+=games[i][k];
                            tail->score+=games[i][k+1];
                            games[i][k]=0;
                            flag[i][k+1]=true;
                            flag[i][k]=true;
                            movement=true;
                        }  
                    }                
                }
            }
        }
    }
    resetflag();
    if (movement==true)
    {
        randomPosition();
    }
}
void space(int angka){
    int spasi;
    if (angka<10){
        spasi=3;
    }else if(angka<100){
        spasi=2;
    }else if(angka<1000){
        spasi=1;
    }else if(angka>=1000){
        spasi=0;
    }
    for (int i = 0; i < spasi; i++)
    {
        cout<<" ";
    }
}
void resetvalue(){
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            games[i][j]=0;
        }  
    }
}
int highscore(){
    int max;
    current=head;
    max=current->score;
    while(current!=NULL){
        if (current->score>max)
        {
            max=current->score;
        }
        current=current->next;
    }
    return max;
}
void backup(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            backup_games[i][j]=games[i][j];
        }   
    }
    backup_score=tail->score;
}
void undoPermainan(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            games[i][j]=backup_games[i][j];
        }
    }
    tail->score=backup_score;
}
int statuspermainan(){
    int status=0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (games[i][j]!=0){
                if (games[i][j]==2048){
                    status=-1;
                    return status;
                }
                if (i-1==-1&&j-1==-1){
                    if (games[i][j]!=games[i+1][j]&&games[i+1]!=0){
                        if (games[i][j]!=games[i][j+1]&&games[i][j+1]!=0){
                            status+=1;
                        }  
                    }
                }else if(i+1==4&&j-1==-1){
                    if (games[i][j]!=games[i-1][j]&&games[i-1]!=0){
                        if (games[i][j]!=games[i][j+1]&&games[i][j+1]!=0){
                            status+=1;
                        }  
                    }
                }else if(i+1==4&&j+1==4){
                    if (games[i][j]!=games[i-1][j]&&games[i-1]!=0){
                        if (games[i][j]!=games[i][j-1]&&games[i][j-1]!=0){
                            status+=1;
                        }  
                    }
                }else if(i-1==-1&&j+1==4){
                    if (games[i][j]!=games[i+1][j]&&games[i+1]!=0){
                        if (games[i][j]!=games[i][j-1]&&games[i][j-1]!=0){
                            status+=1;
                        }  
                    }
                }else if (i-1==-1){
                    if (games[i][j]!=games[i+1][j]&&games[i+1][j]!=0){
                        if (games[i][j]!=games[i][j-1]&&games[i][j-1]!=0){
                            if (games[i][j]!=games[i][j+1]&&games[i][j+1]!=0){
                                status+=1;
                            }   
                        }    
                    }
                }else if (i+1==4){
                    if (games[i][j]!=games[i-1][j]&&games[i-1][j]!=0){
                        if (games[i][j]!=games[i][j-1]&&games[i][j-1]!=0){
                            if (games[i][j]!=games[i][j+1]&&games[i][j+1]!=0){
                                status+=1;
                            }   
                        }    
                    }
                }else if (j-1==-1){
                    if (games[i][j]!=games[i][j+1]&&games[i][j+1]!=0){
                        if (games[i][j]!=games[i-1][j]&&games[i-1][j]!=0){
                            if (games[i][j]!=games[i+1][j]&&games[i+1][j]!=0){
                                status+=1;
                            }   
                        }    
                    }
                }else if (j+1==4){
                    if (games[i][j]!=games[i][j-1]&&games[i][j-1]!=0){
                        if (games[i][j]!=games[i-1][j]&&games[i-1][j]!=0){
                            if (games[i][j]!=games[i+1][j]&&games[i+1][j]!=0){
                                status+=1;
                            }   
                        }    
                    }
                }else if(games[i][j]!=games[i-1][j]&&games[i-1][j]!=0){
                    if(games[i][j]!=games[i+1][j]&&games[i+1][j]!=0){
                        if(games[i][j]!=games[i][j-1]&&games[i][j-1]!=0){
                            if(games[i][j]!=games[i][j+1]&&games[i][j+1]!=0){
                                status+=1;
                            }
                        }
                    }
                } 
            }
        }  
    }
    return status;
}
void display_games(){
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"======== !!!2048!!! ========\n"<<endl;
    cout<<"Score Anda      : "<<tail->score<<endl;
    cout<<"Score Tertinggi : "<<highscore()<<endl<<endl;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (games[i][j]==0){
                cout<<"[    ]  ";
            }
            if (games[i][j]!=0){
                
                SetConsoleTextAttribute(h,log2(games[i][j]));
                cout<<"[";
                space(games[i][j]);cout<<games[i][j]<<"]  ";
                SetConsoleTextAttribute(h,7);   
            }
        }cout<<endl<<endl;
    }
}
int main(){
    int key_input; 
    char input2;
    createPlayer();
    randomPosition();
    permainan:
    display_games();
    if (statuspermainan()==-1){
        cout<<"\n===YOU WIN==="<<endl;
    }else if(statuspermainan()==16){
        cout<<"\n===GAME OVER==="<<endl;
    }
    cout<<"\nGunakan Tombol Arah Pada Keyboard Untuk Menggerakkan......\nTekan Backspace untuk UNDO.....\nTekan Delete Untuk Mengulang\nTekan Esc Untuk Keluar......\n";
    input_ulang:
    key_input=getch();
    if(key_input==224){
        key_input=getch();
    }
    switch (key_input){
    case KEY_UP:
        backup();
        arrow_up();
        system("cls");
        goto permainan;
        break;
    case KEY_DOWN:
        backup();
        arrow_down();
        system("cls");
        goto permainan;
        break;
    case KEY_LEFT:
        backup();
        arrow_left();
        system("cls");
        goto permainan;
        break;
    case KEY_RIGHT:
        backup();
        arrow_right();
        system("cls");
        goto permainan;
        break;
    case KEY_BACKSPACE:
        undoPermainan();
        system("cls");
        goto permainan;
        break;
    case RESET:
        resetvalue();
        createPlayer();
        randomPosition();
        system("cls");
        goto permainan;
    case EXIT:
        system("cls");
        cout<<"Terima Kasih Telah Bermain\n";
        return 0;
        break;
    default:
        cout<<"Inputan Anda Salah!!!\n";
        goto input_ulang;
        break;
    }
}
