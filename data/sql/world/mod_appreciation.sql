SET @Entry := 6000000;

DELETE FROM `npc_text` WHERE `ID` BETWEEN @Entry AND @Entry+2;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES
(@Entry, 'Sorry, there is no character boost available for now.'),
(@Entry+1, 'Which specialization would you like?'),
(@Entry+2, 'Are you absolutely certain you want to do this? I have to destroy all of your current equipment so make sure you save anything you don\'t want to lose!');

DELETE FROM `creature_template` WHERE `entry`=@Entry;
INSERT INTO `creature_template` (`entry`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `unit_class`, `unit_flags`, `type`, `flags_extra`, `ScriptName`) VALUES
(@Entry, 'Ambert Mendenhall', 'Appreciation Assistant', 'Speak', 60, 60, 35, 1, 1, 2, 7, 16777218, 'npc_appreciation');

DELETE FROM `creature_template_model` WHERE `CreatureID`=@Entry;
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`) VALUES
(@Entry, 0, 21697, 1, 1);

DELETE FROM `creature` WHERE `id1`=@Entry;
INSERT INTO `creature` (`id1`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(@Entry, 0, -8801.2, 629.974, 94.2407, 3.06088), -- Stormwind City
(@Entry, 1, 1736.91, -4337.05, 30.7981, 3.77535), -- Orgrimmar
(@Entry, 571, 5867.44, 611.048, 650.489, 2.11311); -- Dalaran
