struct param {
	char name[8];
<<<<<<< HEAD
	int hp, attack, mp;
};
player_setup() {
		struct param CS = { "CS",75,20,10 };
		struct param BS = { "BS",100,5,40 };
		struct param MS = { "MS",125,10,5 };
}
enemy_setup() {
	struct param enemy1 = { "enemy1",50,5,0 };
	struct param enemy2 = { "enemy2",50,5,0 };
	struct param enemy3 = { "enemy3",75,10,2 };
	struct param enemy4 = { "enemy4",110,15,4 };
	struct param enemy5 = { "enemy5",125,15,6 };
	struct param boss = { "boss",150,15,8 };
=======
	int hp, mp, attack;
};
player_setup() {
	if () {
		struct param you = { "CS",100,100,100 };
	}
	else if () {
		struct param you = { "BS",100,100,100 };
	}
	else if () {
		struct param you = { "MS",100,100,100 };
	}
}
enemy_setup() {
	struct param enemy1 = { "enemy1",100,100,100 };
>>>>>>> 213db1f6a7fd1e8ff5153393cbfca7bbc1a4157d
}