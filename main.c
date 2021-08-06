#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	if(*(unsigned long long*)a < *(unsigned long long*)b) {
		return -1;
	} else if(*(unsigned long long*)a == *(unsigned long long*)b) {
		return 0;
	} else {
		return 1;
	}
}

int main(int argc, char* argv[]) {
	unsigned long long test_cases;
	FILE* fp = fopen("input.txt", "r");
	fscanf(fp, "%llu", &test_cases);
	for(unsigned long long i = 0; i < test_cases; i++) {
		unsigned long long team_members;
		fscanf(fp, "%llu", &team_members);
		unsigned long long* g_revolution = (unsigned long long*)malloc(team_members * sizeof(unsigned long long));
		for(unsigned long long j = 0; j < team_members; j++) {
			fscanf(fp, "%llu", &g_revolution[j]);
		}
		unsigned long long* all_starz = (unsigned long long*)malloc(team_members * sizeof(unsigned long long));
		for(unsigned long long j = 0; j < team_members; j++) {
			fscanf(fp, "%llu", &all_starz[j]);
		}
		qsort(g_revolution, team_members, sizeof(unsigned long long), compare);
		qsort(all_starz, team_members, sizeof(unsigned long long), compare);
		unsigned long long possible_wins = 0;
		unsigned long long j = 0;
		for(unsigned long long k = 0; k < team_members; k++) {
			for(; j < team_members; j++) {
				if(g_revolution[j] > all_starz[k]) {
					possible_wins++;
					j++;
					break;
				}
			}
		}
		free(g_revolution);
		free(all_starz);
		printf("%llu\n", possible_wins);
	}
	fclose(fp);
	return 0;
}
