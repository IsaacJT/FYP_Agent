
#define GRIDFILE "RelayTestGrid"
#define RELAYFILE "RelayTestRelay"

#define Simulation
//if commented out then implementation
 
int main()
{
	//make agent
	#ifdef Simulation
		Agent AgentSmith= simulationAgent();
	#else	
		Agent AgentSmith= ImpementAgent();
	#endif

	//read files

	//make GUI
	#ifdef Simulation
		GridGUI True = GridGUI(AgentSmith.getTrue());
	#endif
;
	//Agent run
	while(AgentSmith.done()) //loop until robot job is done. this should never happen for implementation robot
	{
		AgentSmith.findPath();
		AgentSmith.tryPath();
		
	}
}
