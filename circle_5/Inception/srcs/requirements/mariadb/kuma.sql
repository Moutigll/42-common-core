/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19  Distrib 10.11.11-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: kumadb
-- ------------------------------------------------------
-- Server version	10.11.11-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `api_key`
--

DROP TABLE IF EXISTS `api_key`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `api_key` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `key` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `created_date` datetime NOT NULL DEFAULT current_timestamp(),
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `expires` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `api_key_user_id_foreign` (`user_id`),
  CONSTRAINT `api_key_user_id_foreign` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `api_key`
--

LOCK TABLES `api_key` WRITE;
/*!40000 ALTER TABLE `api_key` DISABLE KEYS */;
/*!40000 ALTER TABLE `api_key` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `docker_host`
--

DROP TABLE IF EXISTS `docker_host`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `docker_host` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `docker_daemon` varchar(255) DEFAULT NULL,
  `docker_type` varchar(255) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `docker_host`
--

LOCK TABLES `docker_host` WRITE;
/*!40000 ALTER TABLE `docker_host` DISABLE KEYS */;
/*!40000 ALTER TABLE `docker_host` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `group`
--

DROP TABLE IF EXISTS `group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `group` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `created_date` datetime NOT NULL DEFAULT current_timestamp(),
  `public` tinyint(1) NOT NULL DEFAULT 0,
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `weight` int(11) NOT NULL DEFAULT 1000,
  `status_page_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `group`
--

LOCK TABLES `group` WRITE;
/*!40000 ALTER TABLE `group` DISABLE KEYS */;
/*!40000 ALTER TABLE `group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `heartbeat`
--

DROP TABLE IF EXISTS `heartbeat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `heartbeat` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `important` tinyint(1) NOT NULL DEFAULT 0,
  `monitor_id` int(10) unsigned NOT NULL,
  `status` smallint(6) NOT NULL,
  `msg` text DEFAULT NULL,
  `time` datetime NOT NULL,
  `ping` int(11) DEFAULT NULL,
  `duration` int(11) NOT NULL DEFAULT 0,
  `down_count` int(11) NOT NULL DEFAULT 0,
  `end_time` datetime DEFAULT NULL,
  `retries` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `heartbeat_important_index` (`important`),
  KEY `monitor_time_index` (`monitor_id`,`time`),
  KEY `heartbeat_monitor_id_index` (`monitor_id`),
  KEY `monitor_important_time_index` (`monitor_id`,`important`,`time`),
  CONSTRAINT `heartbeat_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=222 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;


DROP TABLE IF EXISTS `incident`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `incident` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(255) NOT NULL,
  `content` text NOT NULL,
  `style` varchar(30) NOT NULL DEFAULT 'warning',
  `created_date` datetime NOT NULL DEFAULT current_timestamp(),
  `last_updated_date` datetime DEFAULT NULL,
  `pin` tinyint(1) NOT NULL DEFAULT 1,
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `status_page_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `incident`
--

LOCK TABLES `incident` WRITE;
/*!40000 ALTER TABLE `incident` DISABLE KEYS */;
/*!40000 ALTER TABLE `incident` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `knex_migrations`
--

DROP TABLE IF EXISTS `knex_migrations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `knex_migrations` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `batch` int(11) DEFAULT NULL,
  `migration_time` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `knex_migrations`
--

LOCK TABLES `knex_migrations` WRITE;
/*!40000 ALTER TABLE `knex_migrations` DISABLE KEYS */;
INSERT INTO `knex_migrations` VALUES
(1,'2023-08-16-0000-create-uptime.js',1,'2025-05-12 16:02:52'),
(2,'2023-08-18-0301-heartbeat.js',1,'2025-05-12 16:02:52'),
(3,'2023-09-29-0000-heartbeat-retires.js',1,'2025-05-12 16:02:52'),
(4,'2023-10-08-0000-mqtt-query.js',1,'2025-05-12 16:02:52'),
(5,'2023-10-11-1915-push-token-to-32.js',1,'2025-05-12 16:02:52'),
(6,'2023-10-16-0000-create-remote-browsers.js',1,'2025-05-12 16:02:53'),
(7,'2023-12-20-0000-alter-status-page.js',1,'2025-05-12 16:02:53'),
(8,'2023-12-21-0000-stat-ping-min-max.js',1,'2025-05-12 16:02:53'),
(9,'2023-12-22-0000-hourly-uptime.js',1,'2025-05-12 16:02:53'),
(10,'2024-01-22-0000-stats-extras.js',1,'2025-05-12 16:02:53'),
(11,'2024-04-26-0000-snmp-monitor.js',1,'2025-05-12 16:02:53'),
(12,'2024-08-24-000-add-cache-bust.js',1,'2025-05-12 16:02:53'),
(13,'2024-08-24-0000-conditions.js',1,'2025-05-12 16:02:53'),
(14,'2024-10-1315-rabbitmq-monitor.js',1,'2025-05-12 16:02:53'),
(15,'2024-10-31-0000-fix-snmp-monitor.js',1,'2025-05-12 16:02:53'),
(16,'2024-11-27-1927-fix-info-json-data-type.js',1,'2025-05-12 16:02:53'),
(17,'2025-03-25-0127-fix-5721.js',1,'2025-05-12 16:02:53'),
(18,'2025-05-09-0000-add-custom-url.js',1,'2025-05-12 16:02:53');
/*!40000 ALTER TABLE `knex_migrations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `knex_migrations_lock`
--

DROP TABLE IF EXISTS `knex_migrations_lock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `knex_migrations_lock` (
  `index` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `is_locked` int(11) DEFAULT NULL,
  PRIMARY KEY (`index`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `knex_migrations_lock`
--

LOCK TABLES `knex_migrations_lock` WRITE;
/*!40000 ALTER TABLE `knex_migrations_lock` DISABLE KEYS */;
INSERT INTO `knex_migrations_lock` VALUES
(1,0);
/*!40000 ALTER TABLE `knex_migrations_lock` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `maintenance`
--

DROP TABLE IF EXISTS `maintenance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `maintenance` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(150) NOT NULL,
  `description` text NOT NULL,
  `user_id` int(10) unsigned DEFAULT NULL,
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `strategy` varchar(50) NOT NULL DEFAULT 'single',
  `start_date` datetime DEFAULT NULL,
  `end_date` datetime DEFAULT NULL,
  `start_time` time DEFAULT NULL,
  `end_time` time DEFAULT NULL,
  `weekdays` varchar(250) DEFAULT '[]',
  `days_of_month` text DEFAULT '[]',
  `interval_day` int(11) DEFAULT NULL,
  `cron` text DEFAULT NULL,
  `timezone` varchar(255) DEFAULT NULL,
  `duration` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `maintenance_active_index` (`active`),
  KEY `manual_active` (`strategy`,`active`),
  KEY `maintenance_user_id` (`user_id`),
  CONSTRAINT `maintenance_user_id_foreign` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `maintenance`
--

LOCK TABLES `maintenance` WRITE;
/*!40000 ALTER TABLE `maintenance` DISABLE KEYS */;
/*!40000 ALTER TABLE `maintenance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `maintenance_status_page`
--

DROP TABLE IF EXISTS `maintenance_status_page`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `maintenance_status_page` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `status_page_id` int(10) unsigned NOT NULL,
  `maintenance_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `maintenance_status_page_status_page_id_foreign` (`status_page_id`),
  KEY `maintenance_status_page_maintenance_id_foreign` (`maintenance_id`),
  CONSTRAINT `maintenance_status_page_maintenance_id_foreign` FOREIGN KEY (`maintenance_id`) REFERENCES `maintenance` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `maintenance_status_page_status_page_id_foreign` FOREIGN KEY (`status_page_id`) REFERENCES `status_page` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `maintenance_status_page`
--

LOCK TABLES `maintenance_status_page` WRITE;
/*!40000 ALTER TABLE `maintenance_status_page` DISABLE KEYS */;
/*!40000 ALTER TABLE `maintenance_status_page` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `monitor`
--

DROP TABLE IF EXISTS `monitor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `monitor` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(150) DEFAULT NULL,
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `user_id` int(10) unsigned DEFAULT NULL,
  `interval` int(11) NOT NULL DEFAULT 20,
  `url` text DEFAULT NULL,
  `type` varchar(20) DEFAULT NULL,
  `weight` int(11) DEFAULT 2000,
  `hostname` varchar(255) DEFAULT NULL,
  `port` int(11) DEFAULT NULL,
  `created_date` datetime NOT NULL DEFAULT current_timestamp(),
  `keyword` varchar(255) DEFAULT NULL,
  `maxretries` int(11) NOT NULL DEFAULT 0,
  `ignore_tls` tinyint(1) NOT NULL DEFAULT 0,
  `upside_down` tinyint(1) NOT NULL DEFAULT 0,
  `maxredirects` int(11) NOT NULL DEFAULT 10,
  `accepted_statuscodes_json` text NOT NULL DEFAULT '["200-299"]',
  `dns_resolve_type` varchar(5) DEFAULT NULL,
  `dns_resolve_server` varchar(255) DEFAULT NULL,
  `dns_last_result` varchar(255) DEFAULT NULL,
  `retry_interval` int(11) NOT NULL DEFAULT 0,
  `push_token` varchar(32) DEFAULT NULL,
  `method` text NOT NULL DEFAULT 'GET',
  `body` text DEFAULT NULL,
  `headers` text DEFAULT NULL,
  `basic_auth_user` text DEFAULT NULL,
  `basic_auth_pass` text DEFAULT NULL,
  `docker_host` int(10) unsigned DEFAULT NULL,
  `docker_container` varchar(255) DEFAULT NULL,
  `proxy_id` int(10) unsigned DEFAULT NULL,
  `expiry_notification` tinyint(1) DEFAULT 1,
  `mqtt_topic` text DEFAULT NULL,
  `mqtt_success_message` varchar(255) DEFAULT NULL,
  `mqtt_username` varchar(255) DEFAULT NULL,
  `mqtt_password` varchar(255) DEFAULT NULL,
  `database_connection_string` varchar(2000) DEFAULT NULL,
  `database_query` text DEFAULT NULL,
  `auth_method` varchar(250) DEFAULT NULL,
  `auth_domain` text DEFAULT NULL,
  `auth_workstation` text DEFAULT NULL,
  `grpc_url` varchar(255) DEFAULT NULL,
  `grpc_protobuf` text DEFAULT NULL,
  `grpc_body` text DEFAULT NULL,
  `grpc_metadata` text DEFAULT NULL,
  `grpc_method` text DEFAULT NULL,
  `grpc_service_name` text DEFAULT NULL,
  `grpc_enable_tls` tinyint(1) NOT NULL DEFAULT 0,
  `radius_username` varchar(255) DEFAULT NULL,
  `radius_password` varchar(255) DEFAULT NULL,
  `radius_calling_station_id` varchar(50) DEFAULT NULL,
  `radius_called_station_id` varchar(50) DEFAULT NULL,
  `radius_secret` varchar(255) DEFAULT NULL,
  `resend_interval` int(11) NOT NULL DEFAULT 0,
  `packet_size` int(11) NOT NULL DEFAULT 56,
  `game` varchar(255) DEFAULT NULL,
  `http_body_encoding` varchar(25) DEFAULT NULL,
  `description` text DEFAULT NULL,
  `tls_ca` text DEFAULT NULL,
  `tls_cert` text DEFAULT NULL,
  `tls_key` text DEFAULT NULL,
  `parent` int(10) unsigned DEFAULT NULL,
  `invert_keyword` tinyint(1) NOT NULL DEFAULT 0,
  `json_path` text DEFAULT NULL,
  `expected_value` varchar(255) DEFAULT NULL,
  `kafka_producer_topic` varchar(255) DEFAULT NULL,
  `kafka_producer_brokers` text DEFAULT NULL,
  `kafka_producer_ssl` tinyint(1) NOT NULL DEFAULT 0,
  `kafka_producer_allow_auto_topic_creation` tinyint(1) NOT NULL DEFAULT 0,
  `kafka_producer_sasl_options` text DEFAULT NULL,
  `kafka_producer_message` text DEFAULT NULL,
  `oauth_client_id` text DEFAULT NULL,
  `oauth_client_secret` text DEFAULT NULL,
  `oauth_token_url` text DEFAULT NULL,
  `oauth_scopes` text DEFAULT NULL,
  `oauth_auth_method` text DEFAULT NULL,
  `timeout` double NOT NULL DEFAULT 0,
  `gamedig_given_port_only` tinyint(1) NOT NULL DEFAULT 1,
  `mqtt_check_type` varchar(255) NOT NULL DEFAULT 'keyword',
  `remote_browser` int(10) unsigned DEFAULT NULL,
  `snmp_oid` varchar(255) DEFAULT NULL,
  `snmp_version` enum('1','2c','3') DEFAULT '2c',
  `json_path_operator` varchar(255) DEFAULT NULL,
  `cache_bust` tinyint(1) NOT NULL DEFAULT 0,
  `conditions` text NOT NULL DEFAULT '[]',
  `rabbitmq_nodes` text DEFAULT NULL,
  `rabbitmq_username` varchar(255) DEFAULT NULL,
  `rabbitmq_password` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `monitor_user_id_foreign` (`user_id`),
  KEY `monitor_docker_host_foreign` (`docker_host`),
  KEY `monitor_proxy_id_foreign` (`proxy_id`),
  KEY `monitor_parent_foreign` (`parent`),
  KEY `monitor_remote_browser_index` (`remote_browser`),
  CONSTRAINT `monitor_docker_host_foreign` FOREIGN KEY (`docker_host`) REFERENCES `docker_host` (`id`),
  CONSTRAINT `monitor_parent_foreign` FOREIGN KEY (`parent`) REFERENCES `monitor` (`id`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `monitor_proxy_id_foreign` FOREIGN KEY (`proxy_id`) REFERENCES `proxy` (`id`),
  CONSTRAINT `monitor_remote_browser_foreign` FOREIGN KEY (`remote_browser`) REFERENCES `remote_browser` (`id`),
  CONSTRAINT `monitor_user_id_foreign` FOREIGN KEY (`user_id`) REFERENCES `user` (`id`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `monitor`
--

LOCK TABLES `monitor` WRITE;
/*!40000 ALTER TABLE `monitor` DISABLE KEYS */;
INSERT INTO `monitor` VALUES
(5,'OSTJourney',1,1,20,'http://ostjourney:5000','http',2000,NULL,NULL,'2025-05-12 16:11:44',NULL,0,1,0,10,'[\"200-299\"]','A','1.1.1.1',NULL,20,NULL,'GET',NULL,NULL,NULL,NULL,NULL,'ostjourney',NULL,0,'','','','',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,0,56,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,'$',NULL,NULL,'[]',0,0,'{\"mechanism\":\"None\"}',NULL,NULL,NULL,NULL,NULL,'client_secret_basic',48,1,'keyword',NULL,NULL,'2c','==',0,'[]','[]','',''),
(6,'Adminer',1,1,20,'http://adminer:8080','http',2000,NULL,NULL,'2025-05-12 16:14:24',NULL,1,0,0,10,'[\"200-299\"]','A','1.1.1.1',NULL,20,NULL,'GET',NULL,NULL,NULL,NULL,NULL,'',NULL,0,'','','','',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,0,56,NULL,'json',NULL,NULL,NULL,NULL,NULL,0,'$',NULL,NULL,'[]',0,0,'{\"mechanism\":\"None\"}',NULL,NULL,NULL,NULL,NULL,'client_secret_basic',16,1,'keyword',NULL,NULL,'2c','==',0,'[]','[]','',''),
(7,'Wordpress',1,1,20,'https://nginx:443','http',2000,NULL,NULL,'2025-05-12 16:15:04',NULL,0,1,0,10,'[\"200-299\"]','A','1.1.1.1',NULL,20,NULL,'GET',NULL,NULL,NULL,NULL,NULL,'',NULL,0,'','','','',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,0,56,NULL,'json',NULL,NULL,NULL,NULL,NULL,0,'$',NULL,NULL,'[]',0,0,'{\"mechanism\":\"None\"}',NULL,NULL,NULL,NULL,NULL,'client_secret_basic',16,1,'keyword',NULL,NULL,'2c','==',0,'[]','[]','',''),
(8,'MariaDB',1,1,20,'https://','mysql',2000,NULL,NULL,'2025-05-12 16:16:18',NULL,0,0,0,10,'[\"200-299\"]','A','1.1.1.1',NULL,20,NULL,'GET',NULL,NULL,NULL,NULL,NULL,'',NULL,0,'','','','','mysql://ele-lean:unmdp@mariadb:3306/kumadb',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,0,56,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,'$',NULL,NULL,'[]',0,0,'{\"mechanism\":\"None\"}',NULL,NULL,NULL,NULL,NULL,'client_secret_basic',16,1,'keyword',NULL,NULL,'2c','==',0,'[]','[]','',''),
(9,'SFTP',1,1,20,'https://','port',2000,'sftp',22,'2025-05-12 16:18:04',NULL,0,0,0,10,'[\"200-299\"]','A','1.1.1.1',NULL,20,NULL,'GET',NULL,NULL,NULL,NULL,NULL,'',NULL,0,'','','','',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,0,56,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,'$',NULL,NULL,'[]',0,0,'{\"mechanism\":\"None\"}',NULL,NULL,NULL,NULL,NULL,'client_secret_basic',16,1,'keyword',NULL,NULL,'2c','==',0,'[]','[]','','');
/*!40000 ALTER TABLE `monitor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `monitor_group`
--

DROP TABLE IF EXISTS `monitor_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `monitor_group` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `group_id` int(10) unsigned NOT NULL,
  `weight` int(11) NOT NULL DEFAULT 1000,
  `send_url` tinyint(1) NOT NULL DEFAULT 0,
  `custom_url` text DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `monitor_group_group_id_foreign` (`group_id`),
  KEY `fk` (`monitor_id`,`group_id`),
  CONSTRAINT `monitor_group_group_id_foreign` FOREIGN KEY (`group_id`) REFERENCES `group` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `monitor_group_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `monitor_group`
--

LOCK TABLES `monitor_group` WRITE;
/*!40000 ALTER TABLE `monitor_group` DISABLE KEYS */;
/*!40000 ALTER TABLE `monitor_group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `monitor_maintenance`
--

DROP TABLE IF EXISTS `monitor_maintenance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `monitor_maintenance` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `maintenance_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `maintenance_id_index2` (`maintenance_id`),
  KEY `monitor_id_index` (`monitor_id`),
  CONSTRAINT `monitor_maintenance_maintenance_id_foreign` FOREIGN KEY (`maintenance_id`) REFERENCES `maintenance` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `monitor_maintenance_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `monitor_maintenance`
--

LOCK TABLES `monitor_maintenance` WRITE;
/*!40000 ALTER TABLE `monitor_maintenance` DISABLE KEYS */;
/*!40000 ALTER TABLE `monitor_maintenance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `monitor_notification`
--

DROP TABLE IF EXISTS `monitor_notification`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `monitor_notification` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `notification_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `monitor_notification_notification_id_foreign` (`notification_id`),
  KEY `monitor_notification_index` (`monitor_id`,`notification_id`),
  CONSTRAINT `monitor_notification_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `monitor_notification_notification_id_foreign` FOREIGN KEY (`notification_id`) REFERENCES `notification` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `monitor_notification`
--

LOCK TABLES `monitor_notification` WRITE;
/*!40000 ALTER TABLE `monitor_notification` DISABLE KEYS */;
/*!40000 ALTER TABLE `monitor_notification` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `monitor_tag`
--

DROP TABLE IF EXISTS `monitor_tag`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `monitor_tag` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `tag_id` int(10) unsigned NOT NULL,
  `value` text DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `monitor_tag_monitor_id_foreign` (`monitor_id`),
  KEY `monitor_tag_tag_id_foreign` (`tag_id`),
  CONSTRAINT `monitor_tag_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `monitor_tag_tag_id_foreign` FOREIGN KEY (`tag_id`) REFERENCES `tag` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `monitor_tag`
--

LOCK TABLES `monitor_tag` WRITE;
/*!40000 ALTER TABLE `monitor_tag` DISABLE KEYS */;
/*!40000 ALTER TABLE `monitor_tag` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `monitor_tls_info`
--

DROP TABLE IF EXISTS `monitor_tls_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `monitor_tls_info` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `info_json` longtext DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `monitor_tls_info_monitor_id_foreign` (`monitor_id`),
  CONSTRAINT `monitor_tls_info_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `monitor_tls_info`
--

LOCK TABLES `monitor_tls_info` WRITE;
/*!40000 ALTER TABLE `monitor_tls_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `monitor_tls_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `notification`
--

DROP TABLE IF EXISTS `notification`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `notification` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `user_id` int(10) unsigned DEFAULT NULL,
  `is_default` tinyint(1) NOT NULL DEFAULT 0,
  `config` longtext DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `notification`
--

LOCK TABLES `notification` WRITE;
/*!40000 ALTER TABLE `notification` DISABLE KEYS */;
/*!40000 ALTER TABLE `notification` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `notification_sent_history`
--

DROP TABLE IF EXISTS `notification_sent_history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `notification_sent_history` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `type` varchar(50) NOT NULL,
  `monitor_id` int(10) unsigned NOT NULL,
  `days` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `notification_sent_history_type_monitor_id_days_unique` (`type`,`monitor_id`,`days`),
  KEY `good_index` (`type`,`monitor_id`,`days`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `notification_sent_history`
--

LOCK TABLES `notification_sent_history` WRITE;
/*!40000 ALTER TABLE `notification_sent_history` DISABLE KEYS */;
/*!40000 ALTER TABLE `notification_sent_history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proxy`
--

DROP TABLE IF EXISTS `proxy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `proxy` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `protocol` varchar(10) NOT NULL,
  `host` varchar(255) NOT NULL,
  `port` int(11) DEFAULT NULL,
  `auth` tinyint(1) NOT NULL,
  `username` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `default` tinyint(1) NOT NULL DEFAULT 0,
  `created_date` datetime NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`),
  KEY `proxy_user_id` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proxy`
--

LOCK TABLES `proxy` WRITE;
/*!40000 ALTER TABLE `proxy` DISABLE KEYS */;
/*!40000 ALTER TABLE `proxy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `remote_browser`
--

DROP TABLE IF EXISTS `remote_browser`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `remote_browser` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `url` varchar(255) NOT NULL,
  `user_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `remote_browser`
--

LOCK TABLES `remote_browser` WRITE;
/*!40000 ALTER TABLE `remote_browser` DISABLE KEYS */;
/*!40000 ALTER TABLE `remote_browser` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `setting`
--

DROP TABLE IF EXISTS `setting`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `setting` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `key` varchar(200) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `value` text DEFAULT NULL,
  `type` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `setting_key_unique` (`key`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `setting`
--

LOCK TABLES `setting` WRITE;
/*!40000 ALTER TABLE `setting` DISABLE KEYS */;
INSERT INTO `setting` VALUES
(1,'migrateAggregateTableState','\"migrated\"',NULL),
(2,'jwtSecret','$2a$10$QQLw/yD9ERbyDVt/T/7oyeCOhIxjSAtC3QbVxSzVbb5D7jHvUmP/a',NULL),
(3,'initServerTimezone','true',NULL),
(4,'serverTimezone','\"Europe/Paris\"','general'),
(5,'checkUpdate','true','general'),
(6,'searchEngineIndex','false','general'),
(7,'entryPage','\"dashboard\"','general'),
(8,'nscd','true','general'),
(9,'keepDataPeriodDays','0','general'),
(10,'tlsExpiryNotifyDays','[7,14,21]','general'),
(11,'trustProxy','false','general');
/*!40000 ALTER TABLE `setting` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stat_daily`
--

DROP TABLE IF EXISTS `stat_daily`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `stat_daily` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `timestamp` int(11) NOT NULL COMMENT 'Unix timestamp rounded down to the nearest day',
  `ping` float(8,2) NOT NULL COMMENT 'Average ping in milliseconds',
  `up` smallint(6) NOT NULL,
  `down` smallint(6) NOT NULL,
  `ping_min` float(8,2) NOT NULL DEFAULT 0.00 COMMENT 'Minimum ping during this period in milliseconds',
  `ping_max` float(8,2) NOT NULL DEFAULT 0.00 COMMENT 'Maximum ping during this period in milliseconds',
  `extras` text DEFAULT NULL COMMENT 'Extra statistics during this time period',
  PRIMARY KEY (`id`),
  UNIQUE KEY `stat_daily_monitor_id_timestamp_unique` (`monitor_id`,`timestamp`),
  CONSTRAINT `stat_daily_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='This table contains the daily aggregate statistics for each monitor';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stat_daily`
--

LOCK TABLES `stat_daily` WRITE;
/*!40000 ALTER TABLE `stat_daily` DISABLE KEYS */;
INSERT INTO `stat_daily` VALUES
(5,5,1747008000,6.69,16,2,3.00,28.00,NULL),
(6,6,1747008000,17.11,45,0,14.00,32.00,NULL),
(7,7,1747008000,0.00,0,43,0.00,0.00,NULL),
(8,8,1747008000,2.55,38,1,1.00,4.00,NULL),
(9,9,1747008000,0.88,34,0,0.00,2.00,NULL);
/*!40000 ALTER TABLE `stat_daily` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stat_hourly`
--

DROP TABLE IF EXISTS `stat_hourly`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `stat_hourly` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `timestamp` int(11) NOT NULL COMMENT 'Unix timestamp rounded down to the nearest hour',
  `ping` float(8,2) NOT NULL COMMENT 'Average ping in milliseconds',
  `ping_min` float(8,2) NOT NULL DEFAULT 0.00 COMMENT 'Minimum ping during this period in milliseconds',
  `ping_max` float(8,2) NOT NULL DEFAULT 0.00 COMMENT 'Maximum ping during this period in milliseconds',
  `up` smallint(6) NOT NULL,
  `down` smallint(6) NOT NULL,
  `extras` text DEFAULT NULL COMMENT 'Extra statistics during this time period',
  PRIMARY KEY (`id`),
  UNIQUE KEY `stat_hourly_monitor_id_timestamp_unique` (`monitor_id`,`timestamp`),
  CONSTRAINT `stat_hourly_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='This table contains the hourly aggregate statistics for each monitor';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stat_hourly`
--

LOCK TABLES `stat_hourly` WRITE;
/*!40000 ALTER TABLE `stat_hourly` DISABLE KEYS */;
INSERT INTO `stat_hourly` VALUES
(5,5,1747065600,6.69,3.00,28.00,16,2,NULL),
(6,6,1747065600,17.11,14.00,32.00,45,0,NULL),
(7,7,1747065600,0.00,0.00,0.00,0,43,NULL),
(8,8,1747065600,2.55,1.00,4.00,38,1,NULL),
(9,9,1747065600,0.88,0.00,2.00,34,0,NULL);
/*!40000 ALTER TABLE `stat_hourly` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stat_minutely`
--

DROP TABLE IF EXISTS `stat_minutely`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `stat_minutely` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `monitor_id` int(10) unsigned NOT NULL,
  `timestamp` int(11) NOT NULL COMMENT 'Unix timestamp rounded down to the nearest minute',
  `ping` float(8,2) NOT NULL COMMENT 'Average ping in milliseconds',
  `up` smallint(6) NOT NULL,
  `down` smallint(6) NOT NULL,
  `ping_min` float(8,2) NOT NULL DEFAULT 0.00 COMMENT 'Minimum ping during this period in milliseconds',
  `ping_max` float(8,2) NOT NULL DEFAULT 0.00 COMMENT 'Maximum ping during this period in milliseconds',
  `extras` text DEFAULT NULL COMMENT 'Extra statistics during this time period',
  PRIMARY KEY (`id`),
  UNIQUE KEY `stat_minutely_monitor_id_timestamp_unique` (`monitor_id`,`timestamp`),
  CONSTRAINT `stat_minutely_monitor_id_foreign` FOREIGN KEY (`monitor_id`) REFERENCES `monitor` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=95 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='This table contains the minutely aggregate statistics for each monitor';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stat_minutely`
--

LOCK TABLES `stat_minutely` WRITE;
/*!40000 ALTER TABLE `stat_minutely` DISABLE KEYS */;
INSERT INTO `stat_minutely` VALUES
(17,5,1747066260,0.00,0,1,0.00,0.00,NULL),
(18,5,1747066320,0.00,0,1,0.00,0.00,NULL),
(19,5,1747066380,12.00,1,0,12.00,12.00,NULL),
(20,6,1747066440,19.00,2,0,18.00,20.00,NULL),
(21,5,1747066440,9.00,1,0,9.00,9.00,NULL),
(22,6,1747066500,18.33,3,0,15.00,22.00,NULL),
(23,7,1747066500,0.00,0,3,0.00,0.00,NULL),
(24,5,1747066500,4.00,1,0,4.00,4.00,NULL),
(25,6,1747066560,17.00,3,0,14.00,20.00,NULL),
(26,7,1747066560,0.00,0,3,0.00,0.00,NULL),
(27,8,1747066560,2.50,2,1,2.00,3.00,NULL),
(28,5,1747066560,4.00,1,0,4.00,4.00,NULL),
(29,6,1747066620,16.33,3,0,16.00,17.00,NULL),
(30,7,1747066620,0.00,0,3,0.00,0.00,NULL),
(31,8,1747066620,2.67,3,0,2.00,3.00,NULL),
(32,5,1747066620,7.00,1,0,7.00,7.00,NULL),
(33,6,1747066680,15.67,3,0,15.00,17.00,NULL),
(34,9,1747066680,1.00,3,0,1.00,1.00,NULL),
(35,7,1747066680,0.00,0,3,0.00,0.00,NULL),
(36,8,1747066680,2.00,3,0,1.00,3.00,NULL),
(37,5,1747066680,4.00,1,0,4.00,4.00,NULL),
(38,6,1747066740,15.33,3,0,15.00,16.00,NULL),
(39,9,1747066740,1.00,3,0,1.00,1.00,NULL),
(40,7,1747066740,0.00,0,3,0.00,0.00,NULL),
(41,8,1747066740,2.67,3,0,2.00,3.00,NULL),
(42,5,1747066740,4.00,1,0,4.00,4.00,NULL),
(43,6,1747066800,17.00,1,0,17.00,17.00,NULL),
(44,9,1747066800,1.00,1,0,1.00,1.00,NULL),
(45,7,1747066800,0.00,0,1,0.00,0.00,NULL),
(46,5,1747066860,28.00,1,0,28.00,28.00,NULL),
(47,6,1747066860,24.50,2,0,17.00,32.00,NULL),
(48,7,1747066860,0.00,0,2,0.00,0.00,NULL),
(49,8,1747066860,2.50,2,0,2.00,3.00,NULL),
(50,9,1747066860,1.00,2,0,1.00,1.00,NULL),
(51,6,1747066920,16.33,3,0,15.00,18.00,NULL),
(52,7,1747066920,0.00,0,3,0.00,0.00,NULL),
(53,8,1747066920,3.00,3,0,2.00,4.00,NULL),
(54,9,1747066920,1.00,3,0,1.00,1.00,NULL),
(55,5,1747066920,5.00,1,0,5.00,5.00,NULL),
(56,6,1747066980,16.33,3,0,15.00,19.00,NULL),
(57,7,1747066980,0.00,0,3,0.00,0.00,NULL),
(58,8,1747066980,2.00,3,0,2.00,2.00,NULL),
(59,9,1747066980,0.67,3,0,0.00,1.00,NULL),
(60,5,1747066980,4.00,1,0,4.00,4.00,NULL),
(61,6,1747067040,19.00,3,0,16.00,23.00,NULL),
(62,7,1747067040,0.00,0,3,0.00,0.00,NULL),
(63,8,1747067040,3.00,3,0,2.00,4.00,NULL),
(64,9,1747067040,0.67,3,0,0.00,1.00,NULL),
(65,5,1747067040,4.00,1,0,4.00,4.00,NULL),
(66,6,1747067100,18.00,3,0,15.00,20.00,NULL),
(67,7,1747067100,0.00,0,3,0.00,0.00,NULL),
(68,8,1747067100,3.33,3,0,2.00,4.00,NULL),
(69,9,1747067100,1.33,3,0,1.00,2.00,NULL),
(70,5,1747067100,5.00,1,0,5.00,5.00,NULL),
(71,6,1747067160,14.00,3,0,14.00,14.00,NULL),
(72,7,1747067160,0.00,0,3,0.00,0.00,NULL),
(73,8,1747067160,2.00,3,0,2.00,2.00,NULL),
(74,9,1747067160,0.67,3,0,0.00,1.00,NULL),
(75,5,1747067160,3.00,1,0,3.00,3.00,NULL),
(76,6,1747067220,17.67,3,0,15.00,19.00,NULL),
(77,7,1747067220,0.00,0,3,0.00,0.00,NULL),
(78,8,1747067220,2.00,3,0,2.00,2.00,NULL),
(79,9,1747067220,0.67,3,0,0.00,1.00,NULL),
(80,5,1747067220,5.00,1,0,5.00,5.00,NULL),
(81,6,1747067280,16.67,3,0,15.00,19.00,NULL),
(82,7,1747067280,0.00,0,3,0.00,0.00,NULL),
(83,8,1747067280,3.00,3,0,2.00,4.00,NULL),
(84,9,1747067280,0.67,3,0,0.00,1.00,NULL),
(85,5,1747067280,6.00,1,0,6.00,6.00,NULL),
(86,6,1747067340,16.00,3,0,16.00,16.00,NULL),
(87,7,1747067340,0.00,0,3,0.00,0.00,NULL),
(88,8,1747067340,2.67,3,0,2.00,3.00,NULL),
(89,9,1747067340,1.33,3,0,1.00,2.00,NULL),
(90,5,1747067340,3.00,1,0,3.00,3.00,NULL),
(91,6,1747067400,16.00,1,0,16.00,16.00,NULL),
(92,7,1747067400,0.00,0,1,0.00,0.00,NULL),
(93,8,1747067400,2.00,1,0,2.00,2.00,NULL),
(94,9,1747067400,0.00,1,0,0.00,0.00,NULL);
/*!40000 ALTER TABLE `stat_minutely` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `status_page`
--

DROP TABLE IF EXISTS `status_page`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `status_page` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `slug` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `title` varchar(255) NOT NULL,
  `description` text DEFAULT NULL,
  `icon` varchar(255) NOT NULL,
  `theme` varchar(30) NOT NULL,
  `published` tinyint(1) NOT NULL DEFAULT 1,
  `search_engine_index` tinyint(1) NOT NULL DEFAULT 1,
  `show_tags` tinyint(1) NOT NULL DEFAULT 0,
  `password` varchar(255) DEFAULT NULL,
  `created_date` datetime NOT NULL DEFAULT current_timestamp(),
  `modified_date` datetime NOT NULL DEFAULT current_timestamp(),
  `footer_text` text DEFAULT NULL,
  `custom_css` text DEFAULT NULL,
  `show_powered_by` tinyint(1) NOT NULL DEFAULT 1,
  `google_analytics_tag_id` varchar(255) DEFAULT NULL,
  `show_certificate_expiry` tinyint(1) NOT NULL DEFAULT 0,
  `auto_refresh_interval` int(10) unsigned DEFAULT 300,
  PRIMARY KEY (`id`),
  UNIQUE KEY `status_page_slug_unique` (`slug`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `status_page`
--

LOCK TABLES `status_page` WRITE;
/*!40000 ALTER TABLE `status_page` DISABLE KEYS */;
/*!40000 ALTER TABLE `status_page` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `status_page_cname`
--

DROP TABLE IF EXISTS `status_page_cname`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `status_page_cname` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `status_page_id` int(10) unsigned DEFAULT NULL,
  `domain` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `status_page_cname_domain_unique` (`domain`),
  KEY `status_page_cname_status_page_id_foreign` (`status_page_id`),
  CONSTRAINT `status_page_cname_status_page_id_foreign` FOREIGN KEY (`status_page_id`) REFERENCES `status_page` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `status_page_cname`
--

LOCK TABLES `status_page_cname` WRITE;
/*!40000 ALTER TABLE `status_page_cname` DISABLE KEYS */;
/*!40000 ALTER TABLE `status_page_cname` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tag`
--

DROP TABLE IF EXISTS `tag`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `tag` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `color` varchar(255) NOT NULL,
  `created_date` datetime NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tag`
--

LOCK TABLES `tag` WRITE;
/*!40000 ALTER TABLE `tag` DISABLE KEYS */;
/*!40000 ALTER TABLE `tag` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `password` varchar(255) DEFAULT NULL,
  `active` tinyint(1) NOT NULL DEFAULT 1,
  `timezone` varchar(150) DEFAULT NULL,
  `twofa_secret` varchar(64) DEFAULT NULL,
  `twofa_status` tinyint(1) NOT NULL DEFAULT 0,
  `twofa_last_token` varchar(6) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_username_unique` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES
(1,'ele-lean','$2a$10$2HgmTZmDEme3Q78M8uTMe.uR/Jc8uspMDfye3YMyBGPh.DTeosGyK',1,NULL,NULL,0,NULL);
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-05-12 16:30:17
