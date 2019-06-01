#ifndef ITEM_H
#define ITEM_H
class Item {
	public:
		Item();
		~Item();
		int weight, value, id;
		float vw_ratio;
		void show();
};
#endif
