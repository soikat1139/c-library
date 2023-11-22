from youtube_transcript_api import YouTubeTranscriptApi

def get_transcript(video_id):
    
    try:
        transcript = YouTubeTranscriptApi.get_transcript(video_id)

       
        for entry in transcript:
            print(entry['start']  ,entry['text'])
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    video_id=input("Please Input Video Id:")
    get_transcript(video_id)