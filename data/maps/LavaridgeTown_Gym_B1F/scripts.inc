.equ LOCALID_JACE, 1
.equ LOCALID_KEEGAN, 2
.equ LOCALID_JEFF, 3
.equ LOCALID_ELI, 4

LavaridgeTown_Gym_B1F_MapScripts:: @ 81FF87E
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_B1F_OnTransition
	.byte 0

LavaridgeTown_Gym_B1F_OnTransition: @ 81FF884
	call LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars:: @ 81FF88F
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar
	setvar VAR_TEMP_7, 1
LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar:: @ 81FF8B1
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar
	setvar VAR_TEMP_8, 1
LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar:: @ 81FF8BF
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar
	setvar VAR_TEMP_9, 1
LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar:: @ 81FF8CD
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_A, 1
LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars:: @ 81FF8DB
	return

LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers:: @ 81FF8DC
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace
	setobjectmovementtype LOCALID_KEEGAN, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace:: @ 81FF8E9
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff:: @ 81FF8F6
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli
	setobjectmovementtype LOCALID_JEFF, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli:: @ 81FF903
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_ELI, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers:: @ 81FF910
	return