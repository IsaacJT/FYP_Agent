 #ifndef IMPLAMENTAGENT_H
#define IMPLAMENTAGENT_H

namespace Agent{

class ImplementAgent: protected Agent
{
	public:
		inline bool done(){
				//while(something)
				//{wait for something to do}
				return false;			
		}

		void setRelayCount(int numberofRelays);

	private:
		inline void PlaceRelay(int _ID){ //physical shit;
						 super.PlaceRelay(_ID);
						}
		inline void PickupRelay(Relay toAdd){//physical shit;
						 super.PickupRelay(_ID);
							}
			//for now these two are inline, as there is nothing they really do different
};
}
#endif
