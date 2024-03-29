//updated from SA:MP 0.3x by FYP
//updated from SA:MP 0.3z by Pushok, iMaddy, povargek
/*

	PROJECT:		mod_sa
	LICENSE:		See LICENSE in the top level directory
	COPYRIGHT:		Copyright we_sux

	mod_sa is available from http://code.google.com/p/m0d-s0beit-sa/

	mod_sa is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	mod_sa is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with mod_sa.  If not, see <http://www.gnu.org/licenses/>.

*/

#define SAMP_PLAYER_MAX				1004
#define SAMP_VEHICLE_MAX			2000
#define SAMP_PICKUP_MAX				4096
#define SAMP_OBJECTS_MAX			1000
#define SAMP_GANGZONE_MAX			1024
#define MAX_3DTEXT					2048
#define MAX_TEXTDRAW				2048
#define MAX_GANGZONES				1024
#define MAX_PLAYER_NAME				24
#define ALLOWED_PLAYER_NAME_LENGTH	20
#define MAX_CLIENTCMDS				144
#define SAMP_MENUS_MAX				128

#define SAMP_CHAT_INFO_OFFSET			0x212AA4 //0.3z R2
#define SAMP_CHAT_INPUT_INFO_OFFSET     0x212AA8 //0.3z R2
#define SAMP_KILL_INFO_OFFSET			0x212AAC //0.3z R2 
#define SAMP_INFO_OFFSET    			0x212AB8 //0.3z R2
#define SAMP_DIALOG_INFO_OFFSET			0x212A78 //0.3z R2
#define SAMP_MISC_INFO					0x212ACC //0.3z R2 (TODO: struct)

#define SAMP_FONT_OFFSET				0xD2D40 //0.3z R2

#define SAMP_COLOR_OFFSET				0x20FD48 //0.3z R2 
#define VALUE_DRAWING_DISTANCE			0xCECF0 //0.3z R1 (don't change)

// used in proxyIDirect3DDevice9.cpp
#define SAMP_SCOREBOARD_INFO			0x212A74 //0.3z R2
#define SAMP_FUNCUPDATESCOREBOARDDATA   0x7C50 //0.3z R2
#define SAMP_PATCH_NOCARCOLORRESETTING	0xABA30 //0.3z R2
#define SAMP_DRAWTEXTLABELS				0x6E0E1 //0.3z R2

//#define SAMP_GAMEPROCESSHOOK			0x657FA //��� � �������

#define GAMESTATE_AWAIT_JOIN			12
#define GAMESTATE_RESTARTING			17
#define GAMESTATE_WAIT_CONNECT			10
#define GAMESTATE_CONNECTING			11
#define GAMESTATE_CONNECTED				13

#define PLAYER_STATE_NONE				0
#define PLAYER_STATE_ONFOOT				17
#define PLAYER_STATE_PASSENGER			18
#define PLAYER_STATE_DRIVER				19
#define PLAYER_STATE_WASTED				32
#define PLAYER_STATE_SPAWNED			33

#define PLAYER_MARKERS_MODE_OFF			0
#define PLAYER_MARKERS_MODE_GLOBAL		1
#define PLAYER_MARKERS_MODE_STREAMED	2

#define SPECIAL_ACTION_NONE				0
#define SPECIAL_ACTION_DUCK				1
#define SPECIAL_ACTION_USEJETPACK		2
#define SPECIAL_ACTION_ENTER_VEHICLE	3
#define SPECIAL_ACTION_EXIT_VEHICLE     4
#define SPECIAL_ACTION_DANCE1			5
#define SPECIAL_ACTION_DANCE2			6
#define SPECIAL_ACTION_DANCE3			7
#define SPECIAL_ACTION_DANCE4			8
#define SPECIAL_ACTION_HANDSUP			10
#define SPECIAL_ACTION_USECELLPHONE		11
#define SPECIAL_ACTION_SITTING			12
#define SPECIAL_ACTION_STOPUSECELLPHONE 13
#define SPECIAL_ACTION_DRINK_BEER		20
#define SPECIAL_ACTION_SMOKE_CIGGY		21
#define SPECIAL_ACTION_DRINK_WINE		22
#define SPECIAL_ACTION_DRINK_SPRUNK		23
#define SPECIAL_ACTION_CUFFED			24
#define SPECIAL_ACTION_CARRY			25

// SAMP STRUCTURES by Pushok (0.3z R1) | SAMP STRUCTURES by povargek (0.3z R2)

struct stMiscInfo
{
#pragma pack( 1 )
	void			*pUnk0[3];
	VECTOR			 vecCheckpointPos;
	VECTOR			 vecCheckpointSize;
	uint32_t		 iCheckpointEnabled;
	uint16_t		 iCheckpoint_something[2];
	VECTOR			 vecRaceCheckpointPos;
	VECTOR			 vecRaceCheckpointNextPos; //no tested
	uint8_t			 unk1[5];
	uint32_t		 iRaceCheckpointEnabled;
	uint32_t		 unk2[2];
	BYTE			 byteCursor_something;
	uint32_t		 unk3; // FFFFFFFF (changes on mouse click on dialog button)
};

struct stSAMPPools
{
#pragma pack( 1 )
 struct stTextdrawPool *pPool_Textdraw; 
 struct stObjectPool  *pPool_Object; 
 void     *pPool_PlayerLabels;
 struct stGangzonePool *pPool_Gangzone;
 struct stTextLabelPool *pPool_Text3D; 
 struct stPlayerPool  *pPool_Player; 
 struct stVehiclePool *pPool_Vehicle; 
 struct stPickupPool  *pPool_Pickup;
};

struct stSAMP
{
#pragma pack( 1 )
	uint32_t				ulMapIcons[100]; 
	int						iGameState;
	uint32_t				ulConnectTick;
	uint32_t				unk[11];	
	char					szIP[258];
	char					szHostname[258];
	uint8_t					byteUnk1;
	uint32_t				ulPort;
	int						iLanMode;	
	void					 *pRakClientInterface;
	struct stSampSettings	*pSettings;
	struct stSAMPPools		*pPools;
};

struct stDialog 
{ 
#pragma pack( 1 ) 
int unk1[10]; 
int iDialogShowed;
int iDialogType; 
int iDialogID; 
char unk2[1000]; 
};

struct stSampSettings
{
#pragma pack( 1 )
	uint8_t unk_0[5];
	uint8_t	byteNoNametagsBehindWalls;
	uint8_t bytePlayerMarkersMode;
	int		iSpawnsAvailable;	
	uint8_t	unk_11[3];
	uint8_t byteShowNameTags;
	uint8_t unk_16;
	uint8_t byteCJWalk;
	int		iUnk_18;
	float	fWorldBoundaries[4];
	uint8_t unk_35;
	float	fGravity;
	uint8_t unk_40;
	int		iUnk_41;
	float	fNameTagsDistance;
	uint8_t byteShowZoneNames; // not tested
	uint8_t byteWorldTime_Hour;
	uint8_t byteWorldTime_Minute;
};

struct stTextdraw
{
#pragma pack( 1 )
	char szText[2403];
	float fLetterWidth;
	float fLetterHeight;
	DWORD dwLetterColor;
	uint8_t byte_unk; // always = 01 (?)
	BYTE byteCenter;
	BYTE byteBox;
	float fBoxSizeX;
	float fBoxSizeY;
	DWORD dwBoxColor;
	BYTE byteProportional;
	DWORD dwShadowColor;
	BYTE byteShadowSize;
	BYTE byteOutline;
	BYTE byteLeft;
	BYTE byteRight;
	BYTE byteStyle; // font style/texture
	uint8_t unk[3]; // 00 00 00
	float fX;
	float fY;
	DWORD unk_9A3;
	uint8_t unk_9A7;
	WORD unk_9A8;
	DWORD unk_9AA;
	DWORD unk_9AE;
	DWORD unk_9B2;
	DWORD unk_9B6;
	WORD unk_9BA;
	WORD unk_9BC;
	uint8_t unk_9BE[2];
	uint8_t unk_9C0;
};

struct stTextdrawPool
{
#pragma pack( 1 )
	int					iIsListed[MAX_TEXTDRAW];
	uint8_t				unk[1024];
	struct stTextdraw	*textdraw[MAX_TEXTDRAW];
};

struct stPickup
{
#pragma pack( 1 )
	int		iModelID;
	int		iType;
	float	fPosition[3];
};

struct stPickupPool
{
#pragma pack( 1 )
 int     iTimePickup[SAMP_PICKUP_MAX];
 uint32_t   ul_GTA_PickupID[SAMP_PICKUP_MAX];
 int     iPickupID[SAMP_PICKUP_MAX];
 uint8_t    unk[SAMP_PICKUP_MAX * 3];
 int     unk_;
 struct stPickup  pickup[SAMP_PICKUP_MAX]; 
};

struct stPlayerPool
{
#pragma pack( 1 )
 uint32_t    iEmpty; // +0
 uint16_t    sLocalPlayerID; // +4
 void     *pVTBL_txtHandler; // +6
 union
 {
  char szLocalPlayerName[16];
  char *pszLocalPlayerName;
 };  // +10
 int      iStrlen_LocalPlayerName;  // +26
 int      iScoreboard_something;  // +30
 struct stLocalPlayer *pLocalPlayer;  // +34
 int      iLocalPlayerPing;  // +38
 int      iLocalPlayerScore; // +42
 struct stRemotePlayer *pRemotePlayer[SAMP_PLAYER_MAX]; // +46
 int      iIsListed[SAMP_PLAYER_MAX]; // +4062
};

struct stSAMPKeys
{
#pragma pack( 1 )
	uint8_t keys_primaryFire : 1;
	uint8_t keys_horn__crouch : 1;
	uint8_t keys_secondaryFire__shoot : 1;
	uint8_t keys_accel__zoomOut : 1;
	uint8_t keys_enterExitCar : 1;
	uint8_t keys_decel__jump : 1;			// on foot: jump or zoom in
	uint8_t keys_circleRight : 1;
	uint8_t keys_aim : 1;					// hydra auto aim or on foot aim
	uint8_t keys_circleLeft : 1;
	uint8_t keys_landingGear__lookback : 1;
	uint8_t keys_unknown__walkSlow : 1;
	uint8_t keys_specialCtrlUp : 1;
	uint8_t keys_specialCtrlDown : 1;
	uint8_t keys_specialCtrlLeft : 1;
	uint8_t keys_specialCtrlRight : 1;
	uint8_t keys__unused : 1;
};

struct stOnFootData //0x44
{
#pragma pack( 1 )
	uint16_t	sLeftRightKeys;
	uint16_t	sUpDownKeys;
	union
	{
		uint16_t			sKeys;
		struct stSAMPKeys	stSampKeys;
	};
	float		fPosition[3];
	float		fQuaternion[4];
	uint8_t		byteHealth;
	uint8_t		byteArmor;
	uint8_t		byteCurrentWeapon;
	uint8_t		byteSpecialAction;
	float		fMoveSpeed[3];
	float		fSurfingOffsets[3];
	uint16_t	sSurfingVehicleID;
	int			iCurrentAnimationID;
};

struct stInCarData //size 0x3F
{
#pragma pack( 1 )
	uint16_t	sVehicleID;
	uint16_t	sLeftRightKeys;
	uint16_t	sUpDownKeys;
	union
	{
		uint16_t			sKeys;
		struct stSAMPKeys	stSampKeys;
	};
	float		fQuaternion[4];
	float		fPosition[3];
	float		fMoveSpeed[3];
	float		fVehicleHealth;
	uint8_t		bytePlayerHealth;
	uint8_t		byteArmor;
	uint8_t		byteCurrentWeapon;
	uint8_t		byteSiren;
	uint8_t		byteLandingGearState;
	uint16_t	sTrailerID;
	union
	{
		uint16_t	HydraThrustAngle[2];	//nearly same value
		float		fTrainSpeed;
	};
};

struct stAimData //size 0x20
{
#pragma pack( 1 )
	BYTE byteCamMode;
	float vecAimf1[3];
	float vecAimPos[3];
	float fAimZ;
	BYTE byteCamExtZoom : 6;	// 0-63 normalized
	BYTE byteWeaponState : 2;	// see eWeaponState
	BYTE bUnk;
};

struct stTrailerData //size 0x36
{
#pragma pack( 1 )
	uint16_t	sTrailerID;
	float		fDirection[3];
	float		fRoll[3];
	float		fPosition[3];
	float		fSpeed[3];
	uint32_t	pad; // fix alignment
};

struct stPassengerData //size 0x1E
{
#pragma pack( 1 )
	uint16_t	sVehicleID;
	uint8_t		byteSeatID;
	uint8_t		byteCurrentWeapon;
	uint8_t		byteHealth;
	uint8_t		byteArmor;
	uint16_t	sLeftRightKeys;
	uint16_t	sUpDownKeys;
	union
	{
		uint16_t			sKeys;
		struct stSAMPKeys	stSampKeys;
	};
	float		fPosition[3];
};

struct stDamageData
{
#pragma pack( 1 )
	uint16_t	sVehicleID_lastDamageProcessed;
	int			iBumperDamage;
	int			iDoorDamage;
	uint8_t		byteLightDamage;
	uint8_t		byteWheelDamage;
};

struct stSurfData
{
#pragma pack( 1 )
	int			iIsSurfing;
	float		fSurfPosition[3];
	int			iUnknown;
	uint16_t	sSurfingVehicleID;
	uint32_t	ulSurfTick;
	// int			iunknown_[2];
	int			iunknown_;
	int			iSurfMode;	//0 = not surfing, 1 = moving (unstable surf), 2 = fixed on vehicle
};

struct stHeadSync // size 0x14
{
#pragma pack( 1 )
	float	fHeadSync[3];
	int		iHeadSyncUpdateTick;
	int		iHeadSyncLookTick;
};

struct stLocalPlayer
{
#pragma pack( 1 )
	struct stSAMPPed		*pSAMP_Actor; // +0
	int						iIsActorAlive; // +4
	int						iIsWasted; // +8
	uint16_t				sCurrentVehicleID;  // +12
	uint16_t				sLastVehicleID;  // +16
	uint16_t				sCurrentAnimID; // +18
	uint16_t				sUnk1; // +20
	int						iIsActive; // +24
	struct stAimData		aimData; // +60
	struct stOnFootData		onFootData; // +128
	struct stPassengerData	passengerData; // +152
	struct stTrailerData	trailerData; // +206
	struct stInCarData		inCarData; // +269
	struct stHeadSync		headSyncData; // +289 
	uint32_t				ulSendTick;
	uint8_t					byteTeamID;
	int						iSpawnSkin;
	uint8_t					byteTeamID2;
	float					fSpawnPos[3];
	float					fSpawnRot;
	BYTE					byteUnknown2[24];
	int						iSpawnClassLoaded;
	int						iSpawnClassID;
	uint32_t				ulSpawnSelectionTick;
	uint32_t				ulSpawnSelectionStart;		
	int						iIsSpectating;
	uint8_t					byteUnknown1;
	uint16_t				sAimingAtPid;
	uint32_t				ulAimTick;
	uint32_t				ulStatsUpdateTick;
	uint32_t				ulWeapUpdateTick;
	uint32_t				ulUnoccupiedTick;
	uint32_t				ulZoneNameTick;
	uint8_t					byteUnknown_756[2];
	uint8_t					byteCurrentWeapon;
	uint8_t					byteWeaponInventory[13];
	int						iWeaponAmmo[13];	
	struct stSurfData		surfData; // +2C6 ?
	int						iPassengerDriveBy;	
	uint8_t					byteCurrentInterior;
	int						iIsInRCVehicle;
	BYTE					byteUnknown4[256];
	int						iRequestToSpawn;
	struct stDamageData		vehicleDamageData;
	int						iClassSelectionOnDeath;	
	int 					iUnknown2;
	int						iUnknown1;
	int						iIsInSpawnScreen;
	uint32_t				ulSpectateTick;
	uint8_t					byteSpectateMode; // 3 = vehicle, 4 = player, side = 14, fixed = 15
	uint8_t					byteSpectateType; // 0 = none, 1 = player, 2 = vehicle
	int						iSpectateID;
	int						iInitiatedSpectating;

	uint8_t					unknown;
	uint32_t				ulUnknownTick;	
	BYTE					byteUnknown3[3];		
	int						iSpawnWeapon[3];
	int						iSpawnAmmo[3];
	uint8_t					byteUnknown5[4];
};
struct stRemotePlayerData 
{
#pragma pack( 1 )
	uint16_t				sPlayerID;
	uint16_t				sVehicleID;
	uint8_t					byteUnknown1[40];
	float					fOnFootPos[3];
	float					fOnFootMoveSpeed[3];
	float					fVehiclePosition[3];
	float					fVehicleMoveSpeed[3];
	uint8_t					byteTeamID; //+5C
	uint8_t					bytePlayerState; //+5D
	uint8_t					byteSeatID; //+5E
	uint32_t				ulUnknownZero2; //+62
	int						iPassengerDriveBy; //+66
	struct stSAMPVehicle	*pSAMP_Vehicle; //+6A
	struct stSAMPPed		*pSAMP_Actor; //+6E
	uint32_t				ulUnknown1; //+72
	int						iUnknown2[2]; //+7A
	uint8_t					Unknown__;  //+7B
	int						iShowNameTag; //+7F
	int						iHasJetPack; //+83
	uint8_t					byteUnk1[3]; //+86
	uint8_t					byteSpecialAction; //+87
	struct stAimData		aimData;//+A7
	struct stInCarData		inCarData;//+E6
	struct stOnFootData		onFootData;//+12A
	struct stTrailerData	trailerData;//??? not tested
	struct stPassengerData	passengerData;//??? not tested
	float					fActorHealth; 
	float					fActorArmor;
	//aimdata headdata probably wrong
	uint32_t				dwLastStreamedInTick; // is 0 when currently streamed in
	int						iGlobalMarkerLoaded;
	struct stHeadSync		headSyncData;
	float					fVehicleRoll[4];
	uint32_t				dwTick;	
	int						iGlobalMarkerLocation[3];
	uint32_t				ulGlobalMarker_GTAID;
};

struct stRemotePlayer 
{
#pragma pack( 1 )
 uint8_t	bUnk1[3]; // +0
 int	 iScore; // +3
 stRemotePlayerData *pPlayerData; // +8
 int     iIsNPC; // +12 (?)
 int     iPing; // +16
 void    *pVTBL_txtHandler; // +20
 union
 {
  char szPlayerName[16];
  char *pszPlayerName;
 }; // +24
 int     iStrlenName; // iStrlenNameMax, numByteReserved?
 int     iStrlenName__; // +40
};

struct stSAMPPed
{
#pragma pack( 1 )
	void				*pVTBL_sampPed; // + 0
	uint8_t				byteUnknown1[60]; // + 4
	struct actor_info	*pGTA_Ped_; // + 64
	uint32_t			ulGTA_Ped_ID; // + 68
	int					usingCellPhone; // + 72
	uint8_t				byteUnknown2[600]; // + 76
	struct actor_info	*pGTA_Ped; // + 676
	uint8_t				byteUnknown3[22]; // + 680
	uint8_t				byteKeysId; // + 701
	uint16_t			ulGTA_UrinateParticle_ID; // + 702
	int					DrinkingOrSmoking;
	int					object_in_hand;
	int					drunkLevel; // +714
	uint8_t				byteUnknown4[5];
	int					isDancing; // +722
	int					danceStyle; // +726
	int					danceMove; // +730
	uint8_t				byteUnknown5[20];
	int					isUrinating;
};

struct stVehiclePool 
{
#pragma pack( 1 ) 
 struct stSAMPVehicle *pSAMP_Vehicle[SAMP_VEHICLE_MAX];
 int      iIsListed[SAMP_VEHICLE_MAX];
 struct vehicle_info  *pGTA_Vehicle[SAMP_VEHICLE_MAX];
 int      iUnknown[SAMP_VEHICLE_MAX*2];
 uint8_t     byteUnknown[0x7E28];
 int      iInitiated; // not tested
 float     fSpawnPos[SAMP_VEHICLE_MAX][3]; 
};

struct stSAMPVehicle
{
#pragma pack( 1 )
	void				*pVTBL_Vehicle; // + 0
	uint8_t				byteUnknown1[60]; // + 4
	struct vehicle_info *pGTA_Vehicle_; // + 64
	uint32_t			ulGTA_Vehicle_ID; // + 68
	uint32_t			ulUnk; // + 72
	struct vehicle_info *pGTA_Vehicle; // + 76
	uint8_t				byteUnknown2[8]; // + 80
	int					iIsMotorOn; // + 88
	int					iIsLightsOn; // + 92
	int					iIsLocked; // + 96
	uint8_t				byteIsObjective; // + 100
	int					iObjectiveBlipCreated; // + 101
	uint8_t				byteUnknown3[20]; // + 105
	uint8_t				byteColor[2]; // + 121
	int					iColorSync; // + 123
	int					iColor_something; // + 128
};

struct stObject
{
#pragma pack( 1 )
	void				*pVTBL_Object;
	uint8_t				unk[60];
	struct object_info	*pGTAObject;
	uint32_t			ulGTA_Object_ID;
};

struct stObjectPool
{
#pragma pack( 1 )
	uint8_t			unk[80];
	int				iIsListed[SAMP_OBJECTS_MAX];
	struct stObject *object[SAMP_OBJECTS_MAX];
};

struct stGangzone
{
	float	fPosition[4];
	DWORD	dwColor;
	DWORD	dwAltColor;
};

struct stGangzonePool
{
	struct stGangzone	*pGangzone[SAMP_GANGZONE_MAX];
	int					iIsListed[SAMP_GANGZONE_MAX];
};

struct stTextLabel
{
#pragma pack( 1 )
	char		*pText;
	DWORD		color;
	float		fPosition[3];
	float		fMaxViewDistance;
	uint8_t		byteShowBehindWalls;
	uint16_t	sAttachedToPlayerID;
	uint16_t	sAttachedToVehicleID;
};

struct stTextLabelPool
{
#pragma pack( 1 )
	struct stTextLabel	textLabel[MAX_3DTEXT];
	int					iIsListed[MAX_3DTEXT];
};

struct stChatEntry
{
#pragma pack( 1 )
	uint32_t	SystemTime;
	char		szPrefix[28];
	char		szText[144];
	uint8_t		unknown[64];
	int			iType;			// 2 - text + prefix, 4 - text (server msg), 8 - text (debug)
	D3DCOLOR	clTextColor;
	D3DCOLOR	clPrefixColor;	// or textOnly colour
};

struct stChatInfo
{
#pragma pack( 1 )
	int					pagesize; // +0
	void				*pUnk; // +4
	int					iChatWindowMode; // +8 ( 2 - normal, 1 - light, 0 - disabled )
	uint8_t				bTimestamps; // +12
	uint32_t			iUnk; // + 13
	char				logFilePathChatLog[MAX_PATH+1]; // + 17
	void				*pChatbox_unknown[3]; // +288 // probably classes that handle fonts/sprites
	D3DCOLOR			clTextColor; // +290
	D3DCOLOR			clInfoColor; // + 294
	D3DCOLOR			clDebugColor; // +298
	DWORD				dwChatboxOffset; // +302
	struct stChatEntry	chatEntry[100]; // +306
	DWORD				dwChatLinesHeight; // +25506
	DWORD				dwDistanceTextToTimestamp; // 25510
};

struct stInputBox
{
#pragma pack( 1 )
	void	*pUnknown;
	uint8_t	bIsChatboxOpen;
	uint8_t	bIsMouseInChatbox;
	uint8_t	bMouseClick_related;
	uint8_t	unk;
	DWORD	dwPosChatInput[2];
	uint8_t	unk2[263];
	int		iCursorPosition;
	uint8_t	unk3;
	int		iMarkedText_startPos; // Highlighted text between this and iCursorPosition
	uint8_t	unk4[20];
	int		iMouseLeftButton;
};

typedef void ( __cdecl *CMDPROC ) ( PCHAR );
struct stInputInfo
{
#pragma pack( 1 )
	void		*pD3DDevice;
	void		*pDXUTDialog;
	stInputBox	*pDXUTEditBox;
	CMDPROC 	pszCMDs[MAX_CLIENTCMDS];
	char		szCMDNames[MAX_CLIENTCMDS][33];
	int			iCMDCount;
	int			iInputEnabled;
	char		szInputBuffer[129];
	char		szRecallBufffer[10][129];
	char		szCurrentBuffer[129];
	int			iCurrentRecall;
	int			iTotalRecalls;
	CMDPROC 	pszDefaultCMD;
};

struct stKillEntry
{
#pragma pack( 1 )
	char		szKiller[25];
	char		szVictim[25];
	D3DCOLOR	clKillerColor;
	D3DCOLOR	clVictimColor;
	uint8_t		byteType;
};

struct stKillInfo
{
#pragma pack( 1 )
	int					iEnabled;
	struct stKillEntry	killEntry[5];
};

struct stChatPlayer
{
#pragma pack( 1 )
	int			iCreated;
	char		probablyTheText[256]; // text max length = 144
	DWORD		dwTickCreated;
	DWORD		dwLiveLength;
	DWORD		dwColor;
	float		fDrawDistance;
	DWORD		dwUnknown;
};

struct stChatBubbleInfo
{
#pragma pack( 1 )
	struct stChatPlayer	chatBubble[SAMP_PLAYER_MAX];
};

struct stStreamedOutPlayerInfo
{
	int		iPlayerID[SAMP_PLAYER_MAX];
	float	fPlayerPos[SAMP_PLAYER_MAX][3];
};

//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// SUPPORT VARIABLES //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
struct stTranslateGTASAMP_vehiclePool
{
#pragma pack( 1 )
	// the index is the position in the vehicle pool
	//
	// translation data
	int iSAMPID[SAMP_VEHICLE_MAX];
};

struct stTranslateGTASAMP_pedPool
{
#pragma pack( 1 )
	// the index is the position in the ped pool
	//
	// translation data
	int iSAMPID[SAMP_PLAYER_MAX];
};

//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// FUNCTIONS //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void											update_translateGTASAMP_vehiclePool ( void );
void											update_translateGTASAMP_pedPool ( void );

bool											findstrinstr ( char *text, char *find );

int												isBadPtr_SAMP_iVehicleID ( int iVehicleID );
int												isBadPtr_SAMP_iPlayerID ( int iPlayerID );

void											getSamp ();
uint32_t										getSampAddress ();
void											SetupSAMPHook(char *szName, DWORD dwFuncOffset, void *Func, int iType, int iSize, char *szCompareBytes);

struct stSAMP									*stGetSampInfo ( void );
struct stChatInfo								*stGetSampChatInfo ( void );
struct stInputInfo								*stGetInputInfo ( void );
struct stKillInfo								*stGetKillInfo ( void );
D3DCOLOR										samp_color_get ( int id, DWORD trans = 0xFF000000 );

void											sampMainCheat ();

int												getNthPlayerID ( int n );
int												getPlayerCount ( void );
int												getVehicleCount ( void );

int												setLocalPlayerName ( const char *name );
int												getPlayerPos ( int iPlayerID, float fPos[3] );
const char										*getPlayerName ( int iPlayerID );
int												getPlayerState ( int iPlayerID );
int												getPlayerVehicleGTAScriptingID ( int iPlayerID );
int												getPlayerSAMPVehicleID ( int iPlayerID );
void											spectatePlayer(int iPlayerID);
void											spectateHandle();

struct actor_info								*getGTAPedFromSAMPPlayerID ( int iPlayerID );
struct vehicle_info								*getGTAVehicleFromSAMPVehicleID ( int iPlayerID );
int												getSAMPPlayerIDFromGTAPed ( struct actor_info *info );
int												getSAMPVehicleIDFromGTAVehicle ( struct vehicle_info *pVehicle );
uint32_t										getPedGTAScriptingIDFromPlayerID ( int iPlayerID );
uint32_t										getVehicleGTAScriptingIDFromVehicleID ( int iVehicleID );

int												samp_vehicle_find_nearest ( int flags );

bool											get_isModCommandsActive ();
void											init_samp_chat_cmds ();
void											addClientCommand ( char *text, int function );
void											addToChatWindow ( char *text, D3DCOLOR textColor, int playerID = -1 );
void											addMessageToChatWindow ( const char *text, ... );
void											addMessageToChatWindowSS ( const char *text, ... );
void											restartGame ();
void											addSayToChatWindow ( char *msg );
void											say ( char *text, ... );
void											showGameText ( char *text, int time, int textsize );
void											playerSpawn ( void );
void											disconnect ( int reason );
void											setPassword ( char *password );
void											sendSetInterior ( uint8_t interiorID );
void											setSpecialAction ( uint8_t byteSpecialAction );
void											sendSCMEvent ( int iEvent, int iVehicleID, int iParam1, int iParam2 );
void											toggleSAMPCursor(int iToggle);
void 											AddRecallBufer(char* text);

void											installSAMPHooks ();
void											setSAMPCustomSendRates ( int iOnFoot, int iInCar, int iAim, int iHeadSync );
int												sampPatchDisableNameTags ( int iEnabled );
int												sampPatchDisableInteriorUpdate ( int iEnabled );
int												sampPatchDisableScoreboardToggleOn ( int iEnabled );
int												sampPatchDisableChatInputAdjust ( int iEnabled );
void											sendDeath ( void );
void											changeServer( const char *pszIp, unsigned ulPort, const char *pszPassword );

// global pointer externals
extern int										iIsSAMPSupported;
extern int										g_renderSAMP_initSAMPstructs;
extern struct stSAMP							*g_SAMP;
extern struct stPlayerPool						*g_Players;
extern struct stVehiclePool						*g_Vehicles;
extern struct stChatInfo						*g_Chat;
extern struct stInputInfo						*g_Input;
extern struct stKillInfo						*g_DeathList;
extern struct stDialog							*g_Dialog;
struct stDialog									*stGetDialogInfo ( void ); 
extern struct stStreamedOutPlayerInfo			g_stStreamedOutInfo;

// global support variables externals
extern struct stTranslateGTASAMP_vehiclePool	translateGTASAMP_vehiclePool;
extern struct stTranslateGTASAMP_pedPool		translateGTASAMP_pedPool;

extern int										g_iSpectateEnabled;
extern int										g_iCursorEnabled;
extern int										g_iNumPlayersMuted;
extern bool										g_bPlayerMuted[SAMP_PLAYER_MAX];
