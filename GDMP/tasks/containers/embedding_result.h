#ifndef GDMP_TASK_EMBEDDING
#define GDMP_TASK_EMBEDDING

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/variant/packed_float32_array.hpp"
#include "godot_cpp/variant/string.hpp"
#include "godot_cpp/variant/typed_array.hpp"

#include "mediapipe/tasks/cc/components/containers/embedding_result.h"

using namespace godot;
using namespace mediapipe::tasks::components::containers;

class MediaPipeEmbedding : public RefCounted {
		GDCLASS(MediaPipeEmbedding, RefCounted)

	private:
		Embedding embedding;

	protected:
		static void _bind_methods();

	public:
		MediaPipeEmbedding();
		MediaPipeEmbedding(const Embedding &embedding);

		PackedFloat32Array get_float_embedding();
		String get_quantized_embedding();
		int get_head_index();
		String get_head_name();

		bool has_head_name();
};

class MediaPipeEmbeddingResult : public RefCounted {
		GDCLASS(MediaPipeEmbeddingResult, RefCounted)

	private:
		EmbeddingResult result;

	protected:
		static void _bind_methods();

	public:
		MediaPipeEmbeddingResult();
		MediaPipeEmbeddingResult(const EmbeddingResult &result);

		TypedArray<MediaPipeEmbedding> get_embeddings();
		uint64_t get_timestamp_ms();

		bool has_timestamp_ms();
};

#endif
