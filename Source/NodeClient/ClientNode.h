namespace Nodes
{
	class ClientNode
	{
		static hAddress serverNode;
		
		static uint32_t sequenceID;
		static std::unordered_map<uint32_t, std::shared_ptr<ByteBuffer>> pendingData;
		static HANDLE sNodeDiscoveryThread;
		static HANDLE sPacketReceiverThread;
		static std::mutex mutex;

		static DWORD _stdcall NodeDiscoverySender(void  *lparam);
		static DWORD _stdcall NodePacketReceiver(void  *lparam);
		
	public:
		static bool isSNodeConnected;

		static bool InitializeNode();
		static void SetNetworkData(Network::NetworkPacket *inPacket, EventType eventType); 
		static uint32_t GetSequence();
		static int32_t GetFriendCount(int32_t iFriendFlags);
		static uint64_t GetFriendByIndex(int32_t iFriend, int32_t iFriendFlags);
	};
}