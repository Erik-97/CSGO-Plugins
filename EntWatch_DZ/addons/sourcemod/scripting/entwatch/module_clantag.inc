#define EW_MODULE_CLANTAG

char g_sClanTag[MAXPLAYERS + 1][128];

stock void EWM_Clantag_OnPluginStart()
{
	CreateTimer(1.0, EWM_Clantag_Timer_UpdateClantag, _, TIMER_REPEAT);
}

stock void EWM_Clantag_OnPluginEnd()
{
	EWM_Clantag_Mass_Reset();
}

stock void EWM_Clantag_OnMapEnd()
{
	EWM_Clantag_Mass_Reset();
}

stock void EWM_Clantag_OnReloadConfig()
{
	EWM_Clantag_Mass_Reset();
}

stock void EWM_Clantag_Event_RoundStart()
{
	EWM_Clantag_Mass_Reset();
}

stock void EWM_Clantag_OnClientDisconnect(int client)
{
	//Clear stored clantag	
	Format(g_sClanTag[client], sizeof(g_sClanTag[]), "");	
}

stock void EWM_Clantag_Mass_Reset()
{
	for (int i = 1; i <= MaxClients; i++) {
		EWM_Clantag_Reset(i);
		Format(g_sClanTag[i], sizeof(g_sClanTag[]), "");
	}
}

public Action EWM_Clantag_Timer_UpdateClantag(Handle timer, int client)
{
	if (g_bConfigLoaded)
	{
		char buffer_temp[128];
		
		for(int i = 0; i < g_ItemList.Length; i++)
		{
			class_ItemList ItemTest;
			g_ItemList.GetArray(i, ItemTest, sizeof(ItemTest));
			if (ItemTest.Hud && ItemTest.OwnerID != INVALID_ENT_REFERENCE && IsValidEdict(ItemTest.WeaponID))
			{
				char clanName[11];
				FormatEx(clanName, sizeof(clanName), "%s", ItemTest.ShortName);
				
				ItemTest.UpdateTime();
				
				if(ItemTest.CheckDelay() > 0)
				{
					FormatEx(buffer_temp, sizeof(buffer_temp), "%s[-%d]:", clanName, ItemTest.RoundDelay());					
				}
				else
				{
					switch(ItemTest.Mode)
					{
						case 2:
						{
							if (ItemTest.CheckCoolDown() > 0)
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[%d]:", clanName, ItemTest.RoundCoolDown());
							}
							else
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[R]:", clanName);
							}
						}
						case 3:
						{
							if (ItemTest.Uses < ItemTest.MaxUses)
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[%d/%d]:", clanName, ItemTest.Uses, ItemTest.MaxUses);
							}
							else
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[E]:", clanName);
							}
						}
						case 4:
						{
							if (ItemTest.CheckCoolDown() > 0)
							{

								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[%d]:", clanName, ItemTest.RoundCoolDown());
							}
							else
								if (ItemTest.Uses < ItemTest.MaxUses)
								{
									FormatEx(buffer_temp, sizeof(buffer_temp), "%s[%d/%d]:", clanName, ItemTest.Uses, ItemTest.MaxUses);
								}
								else
								{
									FormatEx(buffer_temp, sizeof(buffer_temp), "%s[E]:", clanName);
								}
						}
						case 5:
						{
							if (ItemTest.CheckCoolDown() > 0)
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[%d]:", clanName, ItemTest.RoundCoolDown());
							}
							else
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[%d/%d]:", clanName, ItemTest.Uses, ItemTest.MaxUses);
							}
						}
						case 6, 7:
						{
							if (ItemTest.MathValue > 0)
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[%d/%d]:", clanName, ItemTest.MathValue, ItemTest.MathValueMax);
							}
							else
							{
								FormatEx(buffer_temp, sizeof(buffer_temp), "%s[E]:", clanName);
							}
						}
						default:
						{
							FormatEx(buffer_temp, sizeof(buffer_temp), "%s[+]:", clanName);
						}
					}
				}
				if (IsValidClient(ItemTest.OwnerID)) {
					if (IsPlayerAlive(ItemTest.OwnerID)) {
						CS_SetClientClanTag(ItemTest.OwnerID, buffer_temp);
					}
				}
			}
		}
	}
	return Plugin_Continue;
}

stock void EWM_Clantag_PickUp(class_ItemList ItemTest, int iClient)
{
	if (!IsValidClient(iClient))
		return;
		
	CS_GetClientClanTag(iClient, g_sClanTag[iClient], sizeof(g_sClanTag[]));
	
	if (strlen(g_sClanTag[iClient]) <= 0)
	{
		g_sClanTag[iClient][0] = ' ';
		g_sClanTag[iClient][1] = '\0';
	}	
	
	char buffer_temp[128];
	FormatEx(buffer_temp, 10, "%s", ItemTest.ShortName);
	Format(buffer_temp, sizeof(buffer_temp), "%s[+]:", buffer_temp);
	CS_SetClientClanTag(iClient, buffer_temp);
	CS_SetClientContributionScore(iClient, 9999);
}

stock void EWM_Clantag_Drop(int iClient)
{
	EWM_Clantag_Reset(iClient);
}

stock void EWM_Clantag_PlayerDeath(int iClient)
{
	EWM_Clantag_Reset(iClient);
}

stock void EWM_Clantag_PlayerDeath_Drop(int iClient)
{
	EWM_Clantag_Reset(iClient);
}

stock void EWM_Clantag_Reset(int client)
{
	if (!IsValidClient(client))
		return;
		
	if (strlen(g_sClanTag[client]) > 0)
	{
		if (g_sClanTag[client][1] == '\0' && g_sClanTag[client][0] == ' ') {
			CS_SetClientClanTag(client, "");
		} else {
			CS_SetClientClanTag(client, g_sClanTag[client]);
		}			
	}
	
	CS_SetClientContributionScore(client, 0);
}