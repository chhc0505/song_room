#include<stdio.h>
#include<string.h>

struct room{
	int time;
	int p_num;
	int food_price;
	char room_password[4];
};

int who_are_you();


int main()
{
	if(who_are_you() == 1)
		printf("접속 완료!!\n\n\n");
	else return 0;

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
