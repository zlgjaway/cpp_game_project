#ifndef BOSS_H
#define BOSS_H

class Boss {
  protected:
		// BOSS STATS
		int boss_damage; // fixed for each boss, never changes
		int boss_turn; // fixed for each boss, never changes
		int boss_health; // always changing like a status - health changes based on damage dealt

		// BOSS TIMER (NOT INSIDE THE BOSS, JUST A COUNTER)
		int boss_counter; // always changing like a status - counter resets after attacking

	public:
		Boss();
		Boss(int boss_damage, int boss_turn, int boss_health);

		// Get User's Card Damage and Lower Boss HP
		int take_damage_boss(int card_damage);
		// Called every turn, checks if turn_counter is 0 (attacks user when it reaches 0)
		int deal_damage_boss();

		// Getters and Setters
		int get_boss_damage();
		int get_boss_turn();
		int get_boss_health();
		int get_boss_counter();
		void set_boss_damage(int boss_damage);
		void set_boss_turn(int boss_turn);
		void set_boss_health(int boss_health);
		void set_boss_counter(int boss_counter);

};

#endif

