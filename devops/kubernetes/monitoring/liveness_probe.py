import requests
import logging
import urllib3
import os
import sys

logs_format = '[%(asctime)s] %(levelname)s - %(message)s'
logger = logging.getLogger()

handler = logging.FileHandler('/proc/1/fd/1','w')
logger.setLevel(logging.DEBUG)
formatter = logging.Formatter(logs_format)
handler.setFormatter(formatter)
logger.addHandler(handler)
# disable warnings
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

average_load_value = False
try:
    # fetching the Average load value usage in % 
    average_load_value = os.getloadavg()[0] / os.cpu_count() * 100
    logger.info(f"fetched Average Load value: {average_load_value}")
except Exception as e:
    logger.error(f"Error fetching Average Load Usage value, {e}")

health_api_response = False

try:
    # sending /health request
    health_api_response = requests.get('http://localhost/health')
    logger.info(f"got /health response: {health_api_response.status_code}")
except Exception as e:
    logger.error(f"could not get /health response, {e}")

average_load_fail = False
api_test_fail = False

if not average_load_value:
    average_load_fail = True
    logger.error(f"Failed to fetch Average Load value, the test has been failed!")
elif average_load_value >= 90.0:
    average_load_fail = True
    logger.error(f"Average Load value is above threshold, the test has been failed!")
else:
    logger.debug(f"Success Average Load test")

if not health_api_response:
    api_test_fail = True
    logger.error(f"Could not get /health response, the test has been failed!")
elif health_api_response.status_code != 200:
    api_test_fail = True
    logger.error(f"Bad /health response, the test has been failed!")
elif health_api_response.status_code == 200:
    logger.debug(f"Success /health API test,")

if api_test_fail:
    logger.error(f"Fail /health API test, Liveness probe has failed!, exiting")
    sys.exit(1)
if average_load_fail:
    logger.error(f"Fail Average load test, Liveness probe has failed!, exiting")
    sys.exit(1)

logger.info(f"all tests passed, Liveness probe has succeed!, exiting")
sys.exit(0)