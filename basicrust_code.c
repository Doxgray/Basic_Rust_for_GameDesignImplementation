/*This is a basic implementation of the game play, with some basics functions
All actions are threaded for haven't blocked actions between player and
environement
by Axel DE SOUSA, Student ID : */

life = 10/10;
hunger = 6/6;
thirst = 6/6;
temperature = 15°;
time = 12/24;

while (!Quit)
	{
		SearchStuffs(time++) [Thread]
			{
				SearchWood();
				SearchStone();
			}
		if (life < 10) [Thread]
			{
				SearchFood();
				SearchWater();
			}
		else if (hunger < 6) [Thread]
			{
				SearchFood();
				CraftCampFire(wood, stone);
				CraftCookingMeat(raw meat, camp fire, time++);
				EatCookingMeat(cooking meat, hunger++, life++);
			}
		else if (thirst < 6) [Thread]
			{
				SearchWater();
				CraftCampFire(wood, stone);
				CraftPotableWater(water, camp fire, time++);
				DrinkPotableWater(potable water, thirst++, life++);
			}
		if (temperature < 10°C) [Thread]
			{
				SearchLeaves();
				CraftClothes(leave, wood, time++);
				DressClothes(temperature++);
			}
		else
			life--;
		if (life == 0) [Thread]
			{
				print("You are dead !");
				exit();
			}
		foreach (1minute) [Thread]
			{
				time++;
				if (time == 25)
						time = 1;
				if (time >= 20 || time <= 8)
						temperature--;
				else
						temperature++;
				life--;
				hunger--;
				thirst--;
			}
}
