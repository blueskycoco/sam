#!/bin/sh

make modules
cp drivers/video/s3c-fb.ko ~/tftpboot
