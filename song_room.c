#include<stdio.h>
#include<string.h>

struct room{
	int time;
	int p_num;
	int food_price;
	char room_password[4];
};

int who_are_you();
void print_room(struct room *);
void add_time(struct room *, int);
void subtract_time(struct room *, int);
void room_init(struct  room *, int);
void add_pnum(struct room *, int);


int main()
{	
	int signal = 1;
	int choose1, choose2, choose3;
	int room_num;
	int all_price;

	if(who_are_you() == 1)
		printf("접속 완료!!\n\n\n");
	else return 0;

	struct room rlist[5];


	while(signal){
		printf("1.모든 방 정보 출력\n");
		printf("2.방 정보 변경\n");
		printf("3.음식 주문\n");
		printf("4.총 판매량 출력\n");
		printf("5.프로그램 종료!\n");
		printf("1/2/3/4/5 입력\n");
		scanf("%d" , &choose1);
		printf("\n\n");

		switch(choose1){
			case 1:
				print_room(rlist);
				break;
			case 2:
				printf("1.시간 추가\n");
				printf("2.시간 제거\n");
				printf("3.방 초기화\n");
				printf("4.인원수 추가\n");
				printf("1/2/3/4입력\n");
				scanf("%d", &choose2);
				printf("방 번호:");
				scanf("%d", &room_num);
				printf("\n\n");
				switch(choose2){
					case 1:
						add_time(rlist,room_num);
						break;
					case 2:
						subtract_time(rlist,room_num);
						break;
					case 3:
						room_init(rlist,room_num);
						break;
					case 4:
						add_pnum(rlist,room_num);
						break;

				}
			case 3:
				break;
			case 4:
				break;
			case 5:
				signal = 0;
				break;
		}		


	}


}
int who_are_you(void)
{

	struct user {
		char name[7];
		int pass;
	};


	struct user master = {"Jinseok",5555};
	struct user guest;
	
	printf("사용자 이름 입력:");
	scanf("%s", guest.name);
	for(int i=0; i<7; i++){
		if(master.name[i] != guest.name[i]){
			printf("이름 불일치\n");
			printf("프로그램을 종료합니다!\n");
			return 0;
		}
	}
	
	printf("비밀번호 입력:");
	scanf("%d", &guest.pass);

	if(master.pass != guest.pass){
		printf("비밀번호 불일치!\n");
		printf("프로그램을 종료합니다!\n");
		return 0;
	}

	return 1;
}


void print_room(struct room *rlist){

	for(int i = 0; i < 5; i++){
		printf("%d번방\n",i+1);
		printf("시간:%d\n", (rlist+i)->time);
		printf("인원 수:%d\n", (rlist+i)->p_num);
		printf("음식 값:%d\n", (rlist+i)->food_price);
		printf("방 비밀번호:%s\n\n",(rlist+i)->room_password);

	}
}

void add_time(struct room *rlist, int room_num){
	int add_t;

	printf("추가할 시간:");
	scanf("%d", &add_t);
	
	(rlist+room_num-1)->time += add_t;
	printf("시간 추가완료!\n");
	printf("\n\n");
}


void subtract_time(struct room *rlist, int room_num){
	int sub_t;

	printf("제거할 시간:");
	scanf("%d", &sub_t);

	(rlist+room_num-1)->time -= sub_t;
	printf("시간 제거완료!\n");
	printf("\n\n");
}

void room_init(struct room *rlist, int room_num){
	(rlist+room_num)->time = 0;
	(rlist+room_num)->p_num = 0;
	(rlist+room_num)->food_price = 0;
	strcpy((rlist+room_num)->room_password,"0000");
	printf("%d번방 초기화 완료!\n\n", room_num);
}

void add_pnum(struct room *rlist, int room_num){
	int add_p;
	printf("추가사람 수:");
	scanf("%d", &add_p);

	(rlist+room_num-1)->p_num += add_p;
	printf("인구수 추가 완료!\n");
	printf("\n\n");


}

void menu(struct room *rlist, int room_num,int *all_price ){
	int signal = 1;
	int choose;
	while(signal){
		printf("1.과일 뷔페 29000원\n");
		printf("2.스페셜 마른뷔페 28000원\n");
		printf("3.찹쌀 탕수육 25000원 \n");
		printf("4.수세소세지 28000원 \n");
		printf("5.오돌뼈 + 주먹밥 28000 \n\n");
		printf("6.캔콜라 1000원\n");
		printf("7.캔사이다 1000원\n");
		printf("8.소주 0원\n9.맥주 0원\n");
		printf("1/2/3/4/5/6/7/8 입력:");
		scanf("%d", &choose);
			


	
	}



}
