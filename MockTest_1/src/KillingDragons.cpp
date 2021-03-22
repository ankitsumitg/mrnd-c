/*

Problem Code : Killing Dragons

A prince is on a mission to save the princess.On the way, there is a circular track with N dungeons.
Each dungeon has a dragon, which can be defeated with an energy Ai.
Each dungeon also has a vessel with an energy drink, upon drinking, prince gets extra Bi energy additional to his current energy
In order to save the princess, the prince has to defeat all the dragons.
The prince can choose which dungeon to start from.

Note:
1. The prince cannot defeat a dragon if his current energy level is less than the energy required to kill a dragon.
2. The prince uses only minimum amount of energy to defeat the dragon, and carries the rest with him.
3. The initial energy level of prince is 0.
4. Once the prince enters the circular track, he can advance only in forward direction in order to kill the next dragon.


Input Format:
	1. N - the number of dungeons.
	2. dragonPower - the amount of energy required to defeat the dragon, starting from the 1st dungeon.
	3. energyPortion - the amount of energy in the vessel, starting from the 1st dungeon.


Constraints:
	1 <= N <= 100000
	0 <= Ai, Bi <= 1000

Output Format:
	Return the dungeon number starting at which, the prince can defeat all the dragons.
	If there are multiple possible answers, then return smallest number.
	If prince cannot defeat the dragon return -1.

	
Examples:

1.		Input : N = 3, dragonPower = [1, 5, 7], energyPortion = [2, 6, 3]
		Output : -1

2.		Input : N = 4, dragonPower = [5, 10, 12, 4], energyPortion = [20, 2, 1, 15]
		Output : 4

3.		Input : N = 3, dragonPower = [7, 10, 6], energyPortion = [8, 9, 7]
		Output : 1


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int canSavePrincess(long* dragonPower, long* energyPortion, int noOfDungeons){
	if (dragonPower == NULL || energyPortion == NULL || noOfDungeons <= 0)
		return -1;
	int start = 0;
	while (start < noOfDungeons){
		long remenergy = 0;
		long prin = 0;

		for (int i = 0; i < noOfDungeons; i++) {
			prin = energyPortion[(i + start) % noOfDungeons] + remenergy;
			if (prin >= dragonPower[(i + start) % noOfDungeons])
			{
				remenergy = prin - dragonPower[(i + start) % noOfDungeons];
			}
			else
			{
				break;
			}
			if (i == noOfDungeons - 1)
				return start + 1;
		}
		start++;
	}
	return -1;
}