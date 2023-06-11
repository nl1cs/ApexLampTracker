#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "heltec.h"
#include <ArduinoJson.h>
void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display -> clear();
  Serial.begin(115200);
  WiFi.begin("Abc", "11111111");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi connecting...");
    delay(500);
  }
  Serial.println("Wifi connected");
}

void loop() {

  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    HTTPClient http;

    http.begin("https://api.mozambiquehe.re/bridge?auth=d7225f3fdec52d224d6d738c8f1df3b2&platform=PC&player=JasonMgrass"); //Specify the URL
    int httpCode = http.GET();  //Make the request

    if (httpCode > 0) { //Check for the returning code

      String input = http.getString();
      // Stream& input;

      // Stream& input;

      DynamicJsonDocument doc(12288);

      DeserializationError error = deserializeJson(doc, input);

      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }

      JsonObject global = doc["global"];
      const char* global_name = global["name"]; // "JasonMgrass"
      long long global_uid = global["uid"]; // 1012255303223
      const char* global_avatar = global["avatar"]; // nullptr
      const char* global_platform = global["platform"]; // "PC"
      int global_level = global["level"]; // 375
      int global_toNextLevelPercent = global["toNextLevelPercent"]; // 19
      int global_internalUpdateCount = global["internalUpdateCount"]; // 9923

      JsonObject global_bans = global["bans"];
      bool global_bans_isActive = global_bans["isActive"]; // false
      int global_bans_remainingSeconds = global_bans["remainingSeconds"]; // 0
      const char* global_bans_last_banReason = global_bans["last_banReason"]; // "COMPETITIVE_DODGE_COOLDOWN"

      JsonObject global_rank = global["rank"];
      int global_rank_rankScore = global_rank["rankScore"]; // 1000
      const char* global_rank_rankName = global_rank["rankName"]; // "Bronze"
      int global_rank_rankDiv = global_rank["rankDiv"]; // 4
      int global_rank_ladderPosPlatform = global_rank["ladderPosPlatform"]; // -1
      const char* global_rank_rankImg = global_rank["rankImg"];
      const char* global_rank_rankedSeason = global_rank["rankedSeason"]; // "season14_split_1"

      JsonObject global_arena = global["arena"];
      int global_arena_rankScore = global_arena["rankScore"]; // 0
      const char* global_arena_rankName = global_arena["rankName"]; // "Unranked"
      int global_arena_rankDiv = global_arena["rankDiv"]; // 0
      int global_arena_ladderPosPlatform = global_arena["ladderPosPlatform"]; // -1
      const char* global_arena_rankImg = global_arena["rankImg"];
      const char* global_arena_rankedSeason = global_arena["rankedSeason"]; // "arenas14_split_1"

      const char* global_battlepass_level = global["battlepass"]["level"]; // "-1"

      JsonObject global_battlepass_history = global["battlepass"]["history"];
      int global_battlepass_history_season1 = global_battlepass_history["season1"]; // -1
      int global_battlepass_history_season2 = global_battlepass_history["season2"]; // -1
      int global_battlepass_history_season3 = global_battlepass_history["season3"]; // -1
      int global_battlepass_history_season4 = global_battlepass_history["season4"]; // -1
      int global_battlepass_history_season5 = global_battlepass_history["season5"]; // -1
      int global_battlepass_history_season6 = global_battlepass_history["season6"]; // -1
      int global_battlepass_history_season7 = global_battlepass_history["season7"]; // -1
      int global_battlepass_history_season8 = global_battlepass_history["season8"]; // -1
      int global_battlepass_history_season9 = global_battlepass_history["season9"]; // -1
      int global_battlepass_history_season10 = global_battlepass_history["season10"]; // -1
      int global_battlepass_history_season11 = global_battlepass_history["season11"]; // -1
      int global_battlepass_history_season12 = global_battlepass_history["season12"]; // -1
      int global_battlepass_history_season13 = global_battlepass_history["season13"]; // -1
      int global_battlepass_history_season14 = global_battlepass_history["season14"]; // 0

      int global_internalParsingVersion = global["internalParsingVersion"]; // 2

      for (JsonObject global_badge : global["badges"].as<JsonArray>()) {

        const char* global_badge_name = global_badge["name"]; // "You're Tiering Me Apart: Ranked Season 10", ...
        int global_badge_value = global_badge["value"]; // 3, 0, 0, 0

      }

      int global_levelPrestige = global["levelPrestige"]; // 0

      JsonObject realtime = doc["realtime"];
      const char* realtime_lobbyState = realtime["lobbyState"]; // "open"
      int realtime_isOnline = realtime["isOnline"]; // 0
      int realtime_isInGame = realtime["isInGame"]; // 0
      int realtime_canJoin = realtime["canJoin"]; // 0
      int realtime_partyFull = realtime["partyFull"]; // 0
      const char* realtime_selectedLegend = realtime["selectedLegend"]; // "Pathfinder"
      const char* realtime_currentState = realtime["currentState"]; // "offline"
      int realtime_currentStateSinceTimestamp = realtime["currentStateSinceTimestamp"]; // -1
      const char* realtime_currentStateAsText = realtime["currentStateAsText"]; // "Offline"

      JsonObject legends_selected = doc["legends"]["selected"];
      const char* legends_selected_LegendName = legends_selected["LegendName"]; // "Pathfinder"

      for (JsonObject legends_selected_data_item : legends_selected["data"].as<JsonArray>()) {

        const char* legends_selected_data_item_name = legends_selected_data_item["name"]; // "Scout of Action", ...
        long legends_selected_data_item_value = legends_selected_data_item["value"]; // 114, 4910, 1524474
        const char* legends_selected_data_item_key = legends_selected_data_item["key"];
        bool legends_selected_data_item_global = legends_selected_data_item["global"]; // true, false, false

      }

      JsonObject legends_selected_gameInfo = legends_selected["gameInfo"];
      const char* legends_selected_gameInfo_skin = legends_selected_gameInfo["skin"]; // "Detective Recolor#1"
      const char* legends_selected_gameInfo_skinRarity = legends_selected_gameInfo["skinRarity"];
      const char* legends_selected_gameInfo_frame = legends_selected_gameInfo["frame"]; // "Zipping Through"
      const char* legends_selected_gameInfo_frameRarity = legends_selected_gameInfo["frameRarity"]; // "Epic"
      const char* legends_selected_gameInfo_pose = legends_selected_gameInfo["pose"]; // "Close Up"
      const char* legends_selected_gameInfo_poseRarity = legends_selected_gameInfo["poseRarity"]; // "Epic"
      const char* legends_selected_gameInfo_intro = legends_selected_gameInfo["intro"]; // "It's fun to ...
      const char* legends_selected_gameInfo_introRarity = legends_selected_gameInfo["introRarity"];

      for (JsonObject legends_selected_gameInfo_badge : legends_selected_gameInfo["badges"].as<JsonArray>()) {

        const char* legends_selected_gameInfo_badge_name = legends_selected_gameInfo_badge["name"];
        int legends_selected_gameInfo_badge_value = legends_selected_gameInfo_badge["value"]; // 5, 6, 0
        const char* legends_selected_gameInfo_badge_category = legends_selected_gameInfo_badge["category"];

      }

      const char* legends_selected_ImgAssets_icon = legends_selected["ImgAssets"]["icon"];
      const char* legends_selected_ImgAssets_banner = legends_selected["ImgAssets"]["banner"];

      JsonObject legends_all = doc["legends"]["all"];

      JsonObject legends_all_Global_data_0 = legends_all["Global"]["data"][0];
      const char* legends_all_Global_data_0_name = legends_all_Global_data_0["name"]; // "Scout of Action"
      int legends_all_Global_data_0_value = legends_all_Global_data_0["value"]; // 114
      const char* legends_all_Global_data_0_key = legends_all_Global_data_0["key"];

      int legends_all_Global_data_0_rank_rankPos = legends_all_Global_data_0["rank"]["rankPos"]; // 19850
      float legends_all_Global_data_0_rank_topPercent = legends_all_Global_data_0["rank"]["topPercent"];

      int legends_all_Global_data_0_rankPlatformSpecific_rankPos = legends_all_Global_data_0["rankPlatformSpecific"]["rankPos"];
      float legends_all_Global_data_0_rankPlatformSpecific_topPercent = legends_all_Global_data_0["rankPlatformSpecific"]["topPercent"];

      const char* legends_all_Global_ImgAssets_icon = legends_all["Global"]["ImgAssets"]["icon"];
      const char* legends_all_Global_ImgAssets_banner = legends_all["Global"]["ImgAssets"]["banner"];

      const char* legends_all_Revenant_ImgAssets_icon = legends_all["Revenant"]["ImgAssets"]["icon"];
      const char* legends_all_Revenant_ImgAssets_banner = legends_all["Revenant"]["ImgAssets"]["banner"];

      const char* legends_all_Crypto_ImgAssets_icon = legends_all["Crypto"]["ImgAssets"]["icon"];
      const char* legends_all_Crypto_ImgAssets_banner = legends_all["Crypto"]["ImgAssets"]["banner"];

      const char* legends_all_Horizon_ImgAssets_icon = legends_all["Horizon"]["ImgAssets"]["icon"];
      const char* legends_all_Horizon_ImgAssets_banner = legends_all["Horizon"]["ImgAssets"]["banner"];

      const char* legends_all_Gibraltar_ImgAssets_icon = legends_all["Gibraltar"]["ImgAssets"]["icon"];
      const char* legends_all_Gibraltar_ImgAssets_banner = legends_all["Gibraltar"]["ImgAssets"]["banner"];

      const char* legends_all_Wattson_ImgAssets_icon = legends_all["Wattson"]["ImgAssets"]["icon"];
      const char* legends_all_Wattson_ImgAssets_banner = legends_all["Wattson"]["ImgAssets"]["banner"];

      const char* legends_all_Fuse_ImgAssets_icon = legends_all["Fuse"]["ImgAssets"]["icon"];
      const char* legends_all_Fuse_ImgAssets_banner = legends_all["Fuse"]["ImgAssets"]["banner"];

      JsonObject legends_all_Bangalore = legends_all["Bangalore"];

      JsonObject legends_all_Bangalore_data_0 = legends_all_Bangalore["data"][0];
      const char* legends_all_Bangalore_data_0_name = legends_all_Bangalore_data_0["name"]; // "Double time: ...
      long legends_all_Bangalore_data_0_value = legends_all_Bangalore_data_0["value"]; // 48193
      const char* legends_all_Bangalore_data_0_key = legends_all_Bangalore_data_0["key"];

      long legends_all_Bangalore_data_0_rank_rankPos = legends_all_Bangalore_data_0["rank"]["rankPos"];
      float legends_all_Bangalore_data_0_rank_topPercent = legends_all_Bangalore_data_0["rank"]["topPercent"];

      const char* legends_all_Bangalore_data_0_rankPlatformSpecific_rankPos = legends_all_Bangalore_data_0["rankPlatformSpecific"]["rankPos"];
      const char* legends_all_Bangalore_data_0_rankPlatformSpecific_topPercent = legends_all_Bangalore_data_0["rankPlatformSpecific"]["topPercent"];

      for (JsonObject legends_all_Bangalore_gameInfo_badge : legends_all_Bangalore["gameInfo"]["badges"].as<JsonArray>()) {

        const char* legends_all_Bangalore_gameInfo_badge_name = legends_all_Bangalore_gameInfo_badge["name"];
        int legends_all_Bangalore_gameInfo_badge_value = legends_all_Bangalore_gameInfo_badge["value"]; // 3, 0

      }

      const char* legends_all_Bangalore_ImgAssets_icon = legends_all_Bangalore["ImgAssets"]["icon"];
      const char* legends_all_Bangalore_ImgAssets_banner = legends_all_Bangalore["ImgAssets"]["banner"];

      const char* legends_all_Wraith_ImgAssets_icon = legends_all["Wraith"]["ImgAssets"]["icon"];
      const char* legends_all_Wraith_ImgAssets_banner = legends_all["Wraith"]["ImgAssets"]["banner"];

      const char* legends_all_Octane_ImgAssets_icon = legends_all["Octane"]["ImgAssets"]["icon"];
      const char* legends_all_Octane_ImgAssets_banner = legends_all["Octane"]["ImgAssets"]["banner"];

      const char* legends_all_Bloodhound_ImgAssets_icon = legends_all["Bloodhound"]["ImgAssets"]["icon"];
      const char* legends_all_Bloodhound_ImgAssets_banner = legends_all["Bloodhound"]["ImgAssets"]["banner"];

      const char* legends_all_Caustic_ImgAssets_icon = legends_all["Caustic"]["ImgAssets"]["icon"];
      const char* legends_all_Caustic_ImgAssets_banner = legends_all["Caustic"]["ImgAssets"]["banner"];

      const char* legends_all_Lifeline_ImgAssets_icon = legends_all["Lifeline"]["ImgAssets"]["icon"];
      const char* legends_all_Lifeline_ImgAssets_banner = legends_all["Lifeline"]["ImgAssets"]["banner"];

      JsonObject legends_all_Pathfinder = legends_all["Pathfinder"];

      JsonArray legends_all_Pathfinder_data = legends_all_Pathfinder["data"];

      JsonObject legends_all_Pathfinder_data_0 = legends_all_Pathfinder_data[0];
      const char* legends_all_Pathfinder_data_0_name = legends_all_Pathfinder_data_0["name"]; // "BR ...
      int legends_all_Pathfinder_data_0_value = legends_all_Pathfinder_data_0["value"]; // 6705
      const char* legends_all_Pathfinder_data_0_key = legends_all_Pathfinder_data_0["key"]; // "headshots"

      int legends_all_Pathfinder_data_0_rank_rankPos = legends_all_Pathfinder_data_0["rank"]["rankPos"];
      float legends_all_Pathfinder_data_0_rank_topPercent = legends_all_Pathfinder_data_0["rank"]["topPercent"];

      const char* legends_all_Pathfinder_data_0_rankPlatformSpecific_rankPos = legends_all_Pathfinder_data_0["rankPlatformSpecific"]["rankPos"];
      const char* legends_all_Pathfinder_data_0_rankPlatformSpecific_topPercent = legends_all_Pathfinder_data_0["rankPlatformSpecific"]["topPercent"];

      JsonObject legends_all_Pathfinder_data_1 = legends_all_Pathfinder_data[1];
      const char* legends_all_Pathfinder_data_1_name = legends_all_Pathfinder_data_1["name"]; // "BR Kills"
      int legends_all_Pathfinder_data_1_value = legends_all_Pathfinder_data_1["value"]; // 4910
      const char* legends_all_Pathfinder_data_1_key = legends_all_Pathfinder_data_1["key"];

      long legends_all_Pathfinder_data_1_rank_rankPos = legends_all_Pathfinder_data_1["rank"]["rankPos"];
      float legends_all_Pathfinder_data_1_rank_topPercent = legends_all_Pathfinder_data_1["rank"]["topPercent"];

      int legends_all_Pathfinder_data_1_rankPlatformSpecific_rankPos = legends_all_Pathfinder_data_1["rankPlatformSpecific"]["rankPos"];
      float legends_all_Pathfinder_data_1_rankPlatformSpecific_topPercent = legends_all_Pathfinder_data_1["rankPlatformSpecific"]["topPercent"];

      JsonObject legends_all_Pathfinder_data_2 = legends_all_Pathfinder_data[2];
      const char* legends_all_Pathfinder_data_2_name = legends_all_Pathfinder_data_2["name"]; // "BR Damage"
      long legends_all_Pathfinder_data_2_value = legends_all_Pathfinder_data_2["value"]; // 1524474
      const char* legends_all_Pathfinder_data_2_key = legends_all_Pathfinder_data_2["key"];

      long legends_all_Pathfinder_data_2_rank_rankPos = legends_all_Pathfinder_data_2["rank"]["rankPos"];
      float legends_all_Pathfinder_data_2_rank_topPercent = legends_all_Pathfinder_data_2["rank"]["topPercent"];

      int legends_all_Pathfinder_data_2_rankPlatformSpecific_rankPos = legends_all_Pathfinder_data_2["rankPlatformSpecific"]["rankPos"];
      float legends_all_Pathfinder_data_2_rankPlatformSpecific_topPercent = legends_all_Pathfinder_data_2["rankPlatformSpecific"]["topPercent"];

      JsonObject legends_all_Pathfinder_data_3 = legends_all_Pathfinder_data[3];
      const char* legends_all_Pathfinder_data_3_name = legends_all_Pathfinder_data_3["name"]; // "BR Wins"
      int legends_all_Pathfinder_data_3_value = legends_all_Pathfinder_data_3["value"]; // 73
      const char* legends_all_Pathfinder_data_3_key = legends_all_Pathfinder_data_3["key"];

      long legends_all_Pathfinder_data_3_rank_rankPos = legends_all_Pathfinder_data_3["rank"]["rankPos"];
      float legends_all_Pathfinder_data_3_rank_topPercent = legends_all_Pathfinder_data_3["rank"]["topPercent"];

      const char* legends_all_Pathfinder_data_3_rankPlatformSpecific_rankPos = legends_all_Pathfinder_data_3["rankPlatformSpecific"]["rankPos"];
      const char* legends_all_Pathfinder_data_3_rankPlatformSpecific_topPercent = legends_all_Pathfinder_data_3["rankPlatformSpecific"]["topPercent"];

      for (JsonObject legends_all_Pathfinder_gameInfo_badge : legends_all_Pathfinder["gameInfo"]["badges"].as<JsonArray>()) {

        const char* legends_all_Pathfinder_gameInfo_badge_name = legends_all_Pathfinder_gameInfo_badge["name"];
        int legends_all_Pathfinder_gameInfo_badge_value = legends_all_Pathfinder_gameInfo_badge["value"]; // 5, ...

      }

      const char* legends_all_Pathfinder_ImgAssets_icon = legends_all_Pathfinder["ImgAssets"]["icon"];
      const char* legends_all_Pathfinder_ImgAssets_banner = legends_all_Pathfinder["ImgAssets"]["banner"];

      const char* legends_all_Loba_ImgAssets_icon = legends_all["Loba"]["ImgAssets"]["icon"];
      const char* legends_all_Loba_ImgAssets_banner = legends_all["Loba"]["ImgAssets"]["banner"];

      const char* legends_all_Mirage_ImgAssets_icon = legends_all["Mirage"]["ImgAssets"]["icon"];
      const char* legends_all_Mirage_ImgAssets_banner = legends_all["Mirage"]["ImgAssets"]["banner"];

      const char* legends_all_Rampart_ImgAssets_icon = legends_all["Rampart"]["ImgAssets"]["icon"];
      const char* legends_all_Rampart_ImgAssets_banner = legends_all["Rampart"]["ImgAssets"]["banner"];

      const char* legends_all_Valkyrie_ImgAssets_icon = legends_all["Valkyrie"]["ImgAssets"]["icon"];
      const char* legends_all_Valkyrie_ImgAssets_banner = legends_all["Valkyrie"]["ImgAssets"]["banner"];

      const char* legends_all_Seer_ImgAssets_icon = legends_all["Seer"]["ImgAssets"]["icon"];
      const char* legends_all_Seer_ImgAssets_banner = legends_all["Seer"]["ImgAssets"]["banner"];

      const char* legends_all_Ash_ImgAssets_icon = legends_all["Ash"]["ImgAssets"]["icon"];
      const char* legends_all_Ash_ImgAssets_banner = legends_all["Ash"]["ImgAssets"]["banner"];

      const char* legends_all_Mad_Maggie_ImgAssets_icon = legends_all["Mad Maggie"]["ImgAssets"]["icon"];
      const char* legends_all_Mad_Maggie_ImgAssets_banner = legends_all["Mad Maggie"]["ImgAssets"]["banner"];

      const char* legends_all_Newcastle_ImgAssets_icon = legends_all["Newcastle"]["ImgAssets"]["icon"];
      const char* legends_all_Newcastle_ImgAssets_banner = legends_all["Newcastle"]["ImgAssets"]["banner"];

      const char* legends_all_Vantage_ImgAssets_icon = legends_all["Vantage"]["ImgAssets"]["icon"];
      const char* legends_all_Vantage_ImgAssets_banner = legends_all["Vantage"]["ImgAssets"]["banner"];

      JsonObject mozambiquehere_internal = doc["mozambiquehere_internal"];
      bool mozambiquehere_internal_isNewToDB = mozambiquehere_internal["isNewToDB"]; // false
      const char* mozambiquehere_internal_claimedBy = mozambiquehere_internal["claimedBy"]; // "1662500550"
      const char* mozambiquehere_internal_APIAccessType = mozambiquehere_internal["APIAccessType"]; // "BASIC"
      const char* mozambiquehere_internal_ClusterID = mozambiquehere_internal["ClusterID"]; // "2"

      int mozambiquehere_internal_rate_limit_max_per_second = mozambiquehere_internal["rate_limit"]["max_per_second"];
      // mozambiquehere_internal["rate_limit"]["current_req"] is null

      const char* mozambiquehere_internal_clusterSrv = mozambiquehere_internal["clusterSrv"];

      bool ALS_isALSDataEnabled = doc["ALS"]["isALSDataEnabled"]; // false

      JsonObject total = doc["total"];

      const char* total_scout_of_action_targets_hit_name = total["scout_of_action_targets_hit"]["name"];
      int total_scout_of_action_targets_hit_value = total["scout_of_action_targets_hit"]["value"]; // 114

      const char* total_double_time_distance_name = total["double_time_distance"]["name"]; // "Double time: ...
      long total_double_time_distance_value = total["double_time_distance"]["value"]; // 48193

      const char* total_headshots_name = total["headshots"]["name"]; // "BR Headshots"
      int total_headshots_value = total["headshots"]["value"]; // 6705

      const char* total_specialEvent_kills_name = total["specialEvent_kills"]["name"]; // "BR Kills"
      int total_specialEvent_kills_value = total["specialEvent_kills"]["value"]; // 4910

      const char* total_specialEvent_damage_name = total["specialEvent_damage"]["name"]; // "BR Damage"
      long total_specialEvent_damage_value = total["specialEvent_damage"]["value"]; // 1524474

      const char* total_specialEvent_wins_name = total["specialEvent_wins"]["name"]; // "BR Wins"
      int total_specialEvent_wins_value = total["specialEvent_wins"]["value"]; // 73

      const char* total_kd_value = total["kd"]["value"]; // "-1"
      const char* total_kd_name = total["kd"]["name"]; // "KD"

      String kills = String(legends_all_Pathfinder_data_1_value);
      Heltec.display -> clear();
      Heltec.display->setFont(ArialMT_Plain_16);
      Heltec.display->drawString(0, 0, "Kills:");
      Heltec.display->setFont(ArialMT_Plain_24);
      Heltec.display->drawString(0, 24, kills);
      Heltec.display -> display();

      Serial.print(kills);

    }
    else {
      Serial.println("Error on HTTP request");
    }

    http.end(); //Free the resources
  }

  delay(30000);

}
