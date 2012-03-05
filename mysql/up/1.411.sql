DROP TABLE IF EXISTS `siteclone`;

CREATE TABLE IF NOT EXISTS `siteclone` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `sitename` varchar(60) NOT NULL,
  `password` varchar(32) NOT NULL,
  `email` varchar(64) NOT NULL,
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `verified` boolean DEFAULT '0',
  `md5_key` varchar(32) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `sitename` (`sitename`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;