 #ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include "PathPlan.h"
#include "../Relay/Relay.h"
#include "../Grid/Grid.h"

using namespace environment;
using namespace std;
using namespace Relayspace;
namespace Agentspace{
	class Agent{
		public:
			virtual bool done()=0;

            Agent()
{
   CurrentLocation=Coordinate(0,0);
   KnownWorld.updateSize(Coordinate(1,1));
}

			inline void findPath()
			{
			   // std::cout<<"current"<<CurrentLocation.getRow()<<" "<< CurrentLocation.getColumn()<<std::endl;
			  KnownWorld[CurrentLocation].setViewed(true);
                actionList = planner.findPath(CurrentLocation, Goal,KnownWorld);
			}
			void tryPath();

			virtual void setRelayCount(int numberofRelays)=0; //same, but makes either implemnet, or simulation relays.
			Relay* getRelay(int _ID);
			vector<Relay*> getRelays() {return heldRelays;} //namechange for error provension? na

            inline Grid* getKnownGrid(){return &KnownWorld;}

            void setGoal(RelativeCoordinate relativeToGoal);/**using magic we find where the goal is */

            inline void defineDeploymentMethod(int meth){DeploymentMethod=meth;}
            inline int getDeploymentMethod() {return DeploymentMethod;}

		protected:
		    virtual bool lowSignal()=0;
			virtual bool move(Node::Direction toMove)=0;
			void lookAround();

			void PlaceRelay(Coordinate whereToPlace);
			void PickupRelay(Coordinate PickFrom);

			Coordinate CurrentLocation;
			Coordinate Goal;
			vector<Node::Direction> actionList;
			PathPlan planner;
			Grid KnownWorld;
			vector<Relay*> heldRelays; //relays held on the robot, moved to grid's vector of relays when deployed.
            int DeploymentMethod;

	};
}
#endif
