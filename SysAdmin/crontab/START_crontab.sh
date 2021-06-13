#!/bin/bash
service cron status && \
service cron reload && \
service cron start && \
service cron status
