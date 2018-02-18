#!/usr/bin/env python3
'''
asynchronous example
'''
import asyncio
from asyncio import get_event_loop, sleep
loop = get_event_loop()

async def hello():
    print('Hello', end='', flush =True)
    await sleep(0.5)
    print(' there ', end='', flush =True)
    await sleep(0.5)
    print('World!')

if __name__ == '__main__':
    loop.run_until_complete(hello())
