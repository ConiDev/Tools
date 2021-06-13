#!/bin/bash
service cron status && \
service cron stop && \
service cron status
